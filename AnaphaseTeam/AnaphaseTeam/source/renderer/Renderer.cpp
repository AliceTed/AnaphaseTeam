#include "../../header/renderer/Renderer.h"

#include "../../header/renderer/define/BillBoardRenderDesc.h"
#include "../../header/renderer/define/LightDesc.h"
#include "../../header/renderer/define/MeshDesc.h"
#include "../../header/renderer/define/AnimationRenderDesc.h"
#include "../../header/renderer/define/SkinnedMeshRenderDesc.h"
#include "../../header/renderer/define/OctreeRenderDesc.h"
#include "../../header/renderer/define/SkyBoxRenderDesc.h"

#include "../../header/renderer/define/RectangleRenderDesc.h"
#include "../../header/renderer/define/SpriteRenderDesc.h"
#include "../../header/renderer/define/SpriteRectRenderDesc.h"
#include "../../header/renderer/define/NumberSpriteRenderDesc.h"
#include "../../header/renderer/define/StringRenderDesc.h"
#include "../../header/renderer/define/Type.h"
#include "../../header/renderer/define/ViewportDesc.h"
#include <gslib.h>
#include <sstream>
#include <iomanip>
//#include "../../header/renderer/define/Ray.h"
#include "../../header/shape/Ray.h"

Renderer::Renderer()
{
	mProjectionMatrix.identity();
	mViewMatrix.identity();
}


Renderer::~Renderer()
{
}

void Renderer::initialize()
{
	// ��ʃN���A���̃J���[�̐ݒ�
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	// �ʃJ�����O�̏�����L���ɂ���
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);

	// �f�v�X�o�b�t�@��1.0�ŃN���A����
	glClearDepth(1.0);

	// �A���t�@�e�X�g��L���ɂ���
	glEnable(GL_ALPHA_TEST);

	// �e�v�X�e�X�g��L���ɂ���
	glEnable(GL_DEPTH_TEST);

	// �p�[�X�y�N�e�B�u�␳���s��
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

//�r���[�|�[�g�ݒ�
void Renderer::viewport(const ViewportDesc & desc)
{
	glViewport(desc.x, desc.y, desc.width, desc.height);
	//�r���[�|�[�g�̕ۑ�
	mViewport = desc;
}

//�����ϊ��s��̐ݒ�
void Renderer::perspective(float fov, float aspect, float near, float far)
{
	mProjectionMatrix.setPerspectiveRH(fov, aspect, near, far);
}

//����ϊ��s���ݒ�
void Renderer::lookAt(const Vector3 & eye, const Vector3 & at, const Vector3 & up)
{
	//�e�탌���_�����O���[�h�ޔ�
	glPushAttrib(GL_ENABLE_BIT | GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	//mViewMatrix.setLookAtRH(eye, at, up);
	glGetFloatv(GL_PROJECTION_MATRIX, (GLfloat*)&mProjectionMatrix);
	//����ϊ��s��
	glGetFloatv(GL_MODELVIEW_MATRIX, (GLfloat*)&mViewMatrix);
	
	//�����_�����O���[�h���A
	glPopAttrib();
}

//�r���[�|�[�g�̎擾
const ViewportDesc & Renderer::getViewPort() const
{
	return mViewport;

}
//�����ϊ��s��̎擾
const Matrix4 & Renderer::getProjectionMatrix() const
{
	return mProjectionMatrix;
}
//����ϊ��s��̎擾
const Matrix4 & Renderer::getViewMatrix() const
{
	return mViewMatrix;
}
const LightDesc & Renderer::getLight() const
{
	return mLight;
}
//���C�g�ݒ�
void Renderer::light(const LightDesc & desc)
{
	//���C�g�̌��̐ݒ�������Ȃ�
	glLightfv(GL_LIGHT0, GL_AMBIENT, (float*)&desc.ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, (float*)&desc.diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, (float*)&desc.specular);

	glEnable(GL_LIGHT0);

	//���C�g�p�����[�^�ۑ�
	mLight = desc;
}

Ray Renderer::caluclateRay(const Vector2 & screenPosition)
{
	//�}�E�X�J�[�\���̍��W���E�B���h�E���W�ɕϊ�
	Vector2 window(screenPosition.x, mViewport.height - screenPosition.y);

	//�r���[�|�[�g�ϊ��̋t�ϊ��������Ȃ�
	Vector3 position;
	position.x = (((window.x - mViewport.x)  * 2.0f / mViewport.width) - 1.0f);
	position.y = (((window.y - mViewport.y)  * 2.0f / mViewport.height) - 1.0f);

	//�����ϊ��s��̋t�ϊ��������Ȃ�
	position.x /= mProjectionMatrix.m[0][0];
	position.y /= mProjectionMatrix.m[1][1];
	position.z = -1.0f;

	//����ϊ��s��̋t�s������߂�
	Matrix4 invView(mViewMatrix);
	invView.inverseFast();

	//���C�̈ʒu��ݒ�
	//���C�̕������v�Z
	Vector3 dir = invView.transformNormal(position);
	Ray ray(invView.getPosition(),dir.normalize());
	return ray;
}

//���b�V���`��
void Renderer::render(const MeshRenderDesc & desc)
{
	GScolor currentColor;
	// �J�����g�J���[���擾����
	glGetFloatv(GL_CURRENT_COLOR, (float*)&currentColor);
	//�e�탌���_�����O���[�h�ޔ�
	glPushAttrib(GL_ENABLE_BIT | GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	//�u�����h���@�̐ݒ�
	setBlendFunc(desc.blendFunc);

	//�J���[�̐ݒ�
	glColor4fv((GLfloat*)&desc.color);
	//�����ϊ��s��̐ݒ�
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadMatrixf((GLfloat*)&getProjectionMatrix());
	//����ϊ��s��̐ݒ�
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadMatrixf((GLfloat*)&getViewMatrix());
	//���C�g�̍��W�ݒ�
	GLfloat lightPosition[] = {
		mLight.position.x,
		mLight.position.y,
		mLight.position.z,
		0.0f
	};
	glEnable(GL_LIGHTING);
	glLightfv(GL_LIGHT0,GL_POSITION, lightPosition);
	glEnable(GL_LIGHT0);
	//���b�V���`��
	glMultMatrixf((GLfloat*)&desc.matrix);
	gsDrawMesh(desc.meshID);
	
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();
	//�����_�����O���[�h���A
	glPopAttrib();
	// �J�����g�J���[�𕜋A����
	glColor4fv((float*)&currentColor);
}
void Renderer::render(const SkinnedMeshRenderDesc & desc)
{
	//nsight
	gsBeginShader(desc.shaderID);

	GSvector3 light_position_eye = mLight.position * mViewMatrix;
	gsSetShaderParam3f("u_lightPositionEye", &light_position_eye);
	gsSetShaderParam4f("u_lightAmbient", &mLight.ambient);
	gsSetShaderParam4f("u_lightDiffuse", &mLight.diffuse);
	gsSetShaderParam4f("u_lightSpecular", &mLight.specular);

	gsSetShaderParamMatrix4("u_matWorld", &desc.matrix);
	gsSetShaderParamMatrix4("u_matView", &getViewMatrix());
	gsSetShaderParamMatrix4("u_matProjection", &getProjectionMatrix());
	gsSetShaderParamTexture("u_baseMap", 0);
	gsSetShaderParamTexture("u_normalMap", 1);
	gsSetShaderParam4f("u_color",&desc.color);
	gsSetShaderParamArrayMatrix4("gs_BoneMatrices", gsGetSkeletonNumBones(desc.meshID), desc.animation);

	//���b�V���`��
	gsMeshDrawEx(gsGetMesh(desc.meshID));
	gsEndShader();
}

void Renderer::render(const BillBoardRenderDesc & desc)
{
	//�e�탌���_�����O���[�h�ޔ�
	glPushAttrib(GL_ENABLE_BIT | GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//�ʃJ�����O�𖳌���
	glDisable(GL_CULL_FACE);
	//���C�e�B���O���I�t
	glDisable(GL_LIGHTING);

	//�u�����h���@��ݒ�
	setBlendFunc(desc.blendFunc);

	//�r���{�[�h�����p�̕ϊ��s����쐬
	Matrix4 matBillboard(mViewMatrix);
	matBillboard.setPosition(Vector3(0, 0, 0));
	matBillboard.transpose();

	//���f�����O�ϊ��s��̍쐬
	Matrix4 matModel(desc.matrix);
	matModel.setPosition(Vector3(0, 0, 0));
	matModel *= matBillboard;
	matModel.setPosition(desc.matrix.getPosition());

	//���f���r���[�ϊ��s��̍쐬
	Matrix4 matModelView(matModel * mViewMatrix);

	//�����ϊ��s��̐ݒ�
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadMatrixf((GLfloat*)&mProjectionMatrix);
	//����ϊ��s��̐ݒ�
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadMatrixf((GLfloat*)&matModelView);

	//�e�N�X�`���̃����_�����O���s��
	renderTexture(desc.textureID, desc.rect, desc.srcRect, desc.color);

	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();
	//�����_�����O���[�h���A
	glPopAttrib();
}

void Renderer::render(const SpriteRenderDesc & desc)
{
	// �e�탌���_�����O���[�h�̑ޔ�
	glPushAttrib(GL_ENABLE_BIT | GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// �ʃJ�����O�𖳌��ɂ���
	glDisable(GL_CULL_FACE);
	// ���C�e�B���O�𖳌��ɂ���
	glDisable(GL_LIGHTING);
	// ���o�b�t�@�𖳌��ɂ���
	glDisable(GL_DEPTH_TEST);

	// �u�����h���@�̐ݒ�
	setBlendFunc(desc.blendFunc);

	// �����ϊ��s��̐ݒ�
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(0, mViewport.width, mViewport.height, 0);

	// ���f���r���[�ϊ��s��̐ݒ�
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadMatrixf((GLfloat*)&desc.matrix);

	// ���S�ʒu�̕␳���s��
	glTranslatef(-desc.center.x, -desc.center.y, 0);

	// �e�N�X�`���̃����_�����O���s��
	renderTexture(desc.textureID, desc.color);

	glMatrixMode(GL_PROJECTION);
	glPopMatrix();

	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();

	// �����_�����O���[�h�̕��A
	glPopAttrib();
}

void Renderer::render(const SpriteRectRenderDesc & desc)
{
	// �e�탌���_�����O���[�h�̑ޔ�
	glPushAttrib(GL_ENABLE_BIT | GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// �ʃJ�����O�𖳌��ɂ���
	glDisable(GL_CULL_FACE);
	// ���C�e�B���O�𖳌��ɂ���
	glDisable(GL_LIGHTING);
	// ���o�b�t�@�𖳌��ɂ���
	glDisable(GL_DEPTH_TEST);

	// �u�����h���@�̐ݒ�
	setBlendFunc(desc.blendFunc);

	// �����ϊ��s��̐ݒ�
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(0, mViewport.width, mViewport.height, 0);

	// ���f���r���[�ϊ��s��̐ݒ�
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadMatrixf((GLfloat*)&desc.matrix);

	// ���S�ʒu�̕␳���s��
	glTranslatef(-desc.center.x, -desc.center.y, 0);

	// �X�v���C�g�̕��ƍ��������߂�
	float width = desc.srcRect.right - desc.srcRect.left;
	float height = desc.srcRect.bottom - desc.srcRect.top;
	Rect rect(0, 0, width, height);

	// �e�N�X�`���̃����_�����O���s��
	renderTexture(desc.textureID, rect, desc.srcRect, desc.color);
	
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();

	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();


	// �����_�����O���[�h�̕��A
	glPopAttrib();
}

void Renderer::render(const NumberSpriteRenderDesc & desc)
{
	//�e�탌���_�����O���[�h�ޔ�
	glPushAttrib(GL_ENABLE_BIT | GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	std::ostringstream stream;
	stream << std::fixed << std::setprecision(desc.decimal);
	//�����_��\������ꍇ�͓_�̐����ǉ�
	GSuint digit=desc.digit;
	digit += desc.decimal == 0 ? 0 : 1;
	//0�Ŗ��߂�              �@�@�@�@�@�@�@�@�@�E��
	stream << std::setfill('0') << std::setw(digit) << std::right << desc.number;
	std::string number=stream.str();

	GSmatrix4 mat = desc.matrix;
	for(auto& c:number)
	{
		bool istoken = istoken = (c == '.');

		float x = x = istoken ? 10 : (c - '0');
		x *= desc.size.x;
		SpriteRectRenderDesc sprite;
		sprite.blendFunc = desc.blendFunc;
		sprite.center = desc.center;
		sprite.color = desc.color;
		sprite.matrix = mat;
		sprite.srcRect = GSrect(x, 0, x + desc.size.x, desc.size.y);
		sprite.textureID = desc.textureID;
		render(sprite);
		//�ʒu�����炷 .�Ȃ甼��
		x = desc.size.x;
		x *= istoken ? 0.5f : 1.0f;
		mat.translate(x, 0, 0);
	}
	
	//�����_�����O���[�h���A
	glPopAttrib();
}

void Renderer::render(const StringRenderDesc & desc)
{
	//�e�탌���_�����O���[�h�ޔ�
	glPushAttrib(GL_ENABLE_BIT | GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	GScolor currentColor;
	// �J�����g�J���[���擾����
	glGetFloatv(GL_CURRENT_COLOR, (float*)&currentColor);
	//�����F�̐ݒ�
	glColor4fv((GLfloat*)&desc.color);

	//�����t�H���g�̐�E��
	gsFontParameter(
		desc.font.code,
		desc.font.size,
		desc.font.name.c_str());

	//�\���ʒu�̐ݒ�
	gsTextPos(desc.position.x, desc.position.y);

	//������̕`��
	gsDrawText(desc.string.c_str());
	
	//�����_�����O���[�h���A
	glPopAttrib();
	// �J�����g�J���[�𕜋A����
	glColor4fv((float*)&currentColor);
}

void Renderer::render(const RectangleRenderDesc & desc)
{
	//�e�탌���_�����O���[�h�ޔ�
	glPushAttrib(GL_ENABLE_BIT | GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//�ʃJ�����O�𖳌�
	glDisable(GL_CULL_FACE);
	//���C�e�B���O���I�t
	glDisable(GL_LIGHTING);
	//���o�b�t�@������
	glDisable(GL_DEPTH_TEST);

	//�u�����h���@�̐ݒ�
	setBlendFunc(desc.blendFunc);

	//�����ϊ��s��̐ݒ�
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(0, mViewport.width, mViewport.height, 0);

	//�l�p�`�̕`��
	glBegin(GL_QUADS);
	glColor4fv((GLfloat*)&desc.color);
	glVertex2f(desc.rect.left, desc.rect.top);
	glVertex2f(desc.rect.left, desc.rect.bottom);
	glVertex2f(desc.rect.right, desc.rect.bottom);
	glVertex2f(desc.rect.right, desc.rect.top);
	glEnd();

	glPopMatrix();

	//�����_�����O���[�h���A
	glPopAttrib();
}
void Renderer::render(const OctreeRenderDesc & desc)
{
	//�e�탌���_�����O���[�h�ޔ�
	glPushAttrib(GL_ENABLE_BIT | GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	//�u�����h���@�̐ݒ�
	setBlendFunc(desc.blendFunc);
	//�J���[�̐ݒ�
	glColor4fv((GLfloat*)&desc.color);
	//�����ϊ��s��̐ݒ�
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadMatrixf((GLfloat*)&mProjectionMatrix);
	//����ϊ��s��̐ݒ�
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadMatrixf((GLfloat*)&mViewMatrix);
	//���C�g�̍��W�ݒ�
	GLfloat lightPosition[] = {
		mLight.position.x,
		mLight.position.y,
		mLight.position.z,
		0.0f
	};
	glEnable(GL_LIGHTING);
	glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
	glEnable(GL_LIGHT0);

	gsDrawOctree(desc.octreeID);	
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	//����ϊ��s��̐ݒ�
	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();
	//�����_�����O���[�h���A
	glPopAttrib();
}

void Renderer::render(const SkyBoxRenderDesc & desc)
{
	//�e�탌���_�����O���[�h�ޔ�
	glPushAttrib(GL_ENABLE_BIT | GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	//�u�����h���@�̐ݒ�
	setBlendFunc(desc.blendFunc);
	//�J���[�̐ݒ�
	glColor4fv((GLfloat*)&desc.color);
	//�����ϊ��s��̐ݒ�
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadMatrixf((GLfloat*)&mProjectionMatrix);
	//����ϊ��s��̐ݒ�
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadMatrixf((GLfloat*)&mViewMatrix);
	//���C�g�̍��W�ݒ�
	GLfloat lightPosition[] = {
		mLight.position.x,
		mLight.position.y,
		mLight.position.z,
		0.0f
	};
	glEnable(GL_LIGHTING);
	glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
	glEnable(GL_LIGHT0);

	glMultMatrixf((GLfloat*)&desc.matrix);
	gsDrawSkyBox(desc.meshID);
	
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	//����ϊ��s��̐ݒ�
	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();
	//�����_�����O���[�h���A
	glPopAttrib();
}
//�u�����h�֐��̐ݒ�
void Renderer::setBlendFunc(BlendFunc blendFunc)
{
	//�u�����h��L����
	glEnable(GL_BLEND);

	switch (blendFunc)
	{
	case BlendFunc::NONE://�u�����h�Ȃ�
		glDepthMask(GL_TRUE);
		glDisable(GL_BLEND);
		break;
	case BlendFunc::DEFAULT://�f�t�H���g
		glDepthMask(GL_TRUE);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		break;
	case BlendFunc::ALPHA://�A���t�@�l�ɂ�锼����
		glDepthMask(GL_FALSE);
		glBlendFunc(GL_ONE, GL_ONE_MINUS_SRC_COLOR);
		break;
	case BlendFunc::ADD://���Z�ɂ�锼����
		glDepthMask(GL_FALSE);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE);
		break;
	case BlendFunc::SUB://���Z�ɂ�锼����
		glDepthMask(GL_FALSE);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE);
		break;
	default:
		break;
	}
}

void Renderer::renderTexture(ResourceID id, const Color4 & color)
{
	GScolor currentColor;
	// �J�����g�J���[���擾����
	glGetFloatv(GL_CURRENT_COLOR, (float*)&currentColor);
	// �e�N�X�`�����o�C���h����
	gsBindTexture(id);

	// �o�C���h���̃e�N�X�`���̕��ƍ������擾
	GLsizei texWidth;
	glGetTexLevelParameteriv(GL_TEXTURE_2D, 0, GL_TEXTURE_WIDTH, &texWidth);
	GLsizei	texHeight;
	glGetTexLevelParameteriv(GL_TEXTURE_2D, 0, GL_TEXTURE_HEIGHT, &texHeight);
	// �X�v���C�g�̕��ƍ��������߂�
	GSrect rect(0,0,texWidth,texHeight);
	// �e�N�X�`�����W�̌v�Z���s��
	GSrect texCoord(0.0f,0.0f,1.0f,1.0f);

	// �l�p�`�̕`��
	glBegin(GL_QUADS);
	glColor4fv((GLfloat*)&color);
	glTexCoord2f(texCoord.left, texCoord.top);
	glVertex2f(rect.left, rect.top);
	glTexCoord2f(texCoord.left, texCoord.bottom);
	glVertex2f(rect.left, rect.bottom);
	glTexCoord2f(texCoord.right, texCoord.bottom);
	glVertex2f(rect.right, rect.bottom);
	glTexCoord2f(texCoord.right, texCoord.top);
	glVertex2f(rect.right, rect.top);
	glEnd();

	// �e�N�X�`���𖳌��ɂ���
	glBindTexture(GL_TEXTURE_2D, 0);
	// �J�����g�J���[�𕜋A����
	glColor4fv((float*)&currentColor);
}

void Renderer::renderTexture(ResourceID id, const Rect & rect, const Rect & srcRect, const Color4 & color)
{
	GScolor currentColor;
	// �J�����g�J���[���擾����
	glGetFloatv(GL_CURRENT_COLOR, (float*)&currentColor);
	// �e�N�X�`�����o�C���h����
	gsBindTexture(id);

	// �o�C���h���̃e�N�X�`���̕��ƍ������擾
	GLsizei texWidth;
	glGetTexLevelParameteriv(GL_TEXTURE_2D, 0, GL_TEXTURE_WIDTH, &texWidth);
	GLsizei	texHeight;
	glGetTexLevelParameteriv(GL_TEXTURE_2D, 0, GL_TEXTURE_HEIGHT, &texHeight);

	// �e�N�X�`�����W�̌v�Z���s��
	GSrect texCoord(
		srcRect.left / texWidth,
		srcRect.top / texHeight,
		srcRect.right / texWidth,
		srcRect.bottom / texHeight);

	// �l�p�`�̕`��
	glBegin(GL_QUADS);
	glColor4fv((GLfloat*)&color);
	glTexCoord2f(texCoord.left, texCoord.top);
	glVertex2f(rect.left, rect.top);
	glTexCoord2f(texCoord.left, texCoord.bottom);
	glVertex2f(rect.left, rect.bottom);
	glTexCoord2f(texCoord.right, texCoord.bottom);
	glVertex2f(rect.right, rect.bottom);
	glTexCoord2f(texCoord.right, texCoord.top);
	glVertex2f(rect.right, rect.top);
	glEnd();

	// �e�N�X�`���𖳌��ɂ���
	glBindTexture(GL_TEXTURE_2D, 0);

	// �J�����g�J���[�𕜋A����
	glColor4fv((float*)&currentColor);
}
