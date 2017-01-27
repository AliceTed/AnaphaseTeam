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
	// 画面クリア時のカラーの設定
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	// 面カリングの処理を有効にする
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);

	// デプスバッファを1.0でクリアする
	glClearDepth(1.0);

	// アルファテストを有効にする
	glEnable(GL_ALPHA_TEST);

	// テプステストを有効にする
	glEnable(GL_DEPTH_TEST);

	// パースペクティブ補正を行う
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

//ビューポート設定
void Renderer::viewport(const ViewportDesc & desc)
{
	glViewport(desc.x, desc.y, desc.width, desc.height);
	//ビューポートの保存
	mViewport = desc;
}

//透視変換行列の設定
void Renderer::perspective(float fov, float aspect, float near, float far)
{
	mProjectionMatrix.setPerspectiveRH(fov, aspect, near, far);
}

//視野変換行列を設定
void Renderer::lookAt(const Vector3 & eye, const Vector3 & at, const Vector3 & up)
{
	//mViewMatrix.setLookAtRH(eye, at, up);
	glGetFloatv(GL_PROJECTION_MATRIX, (GLfloat*)&mProjectionMatrix);
	//視野変換行列
	glGetFloatv(GL_MODELVIEW_MATRIX, (GLfloat*)&mViewMatrix);
}

//ビューポートの取得
const ViewportDesc & Renderer::getViewPort() const
{
	return mViewport;

}
//透視変換行列の取得
const Matrix4 & Renderer::getProjectionMatrix() const
{
	return mProjectionMatrix;
}
//視野変換行列の取得
const Matrix4 & Renderer::getViewMatrix() const
{
	return mViewMatrix;
}
const LightDesc & Renderer::getLight() const
{
	return mLight;
}
//ライト設定
void Renderer::light(const LightDesc & desc)
{
	//ライトの光の設定をおこなう
	glLightfv(GL_LIGHT0, GL_AMBIENT, (float*)&desc.ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, (float*)&desc.diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, (float*)&desc.specular);

	glEnable(GL_LIGHT0);

	//ライトパラメータ保存
	mLight = desc;
}

Ray Renderer::caluclateRay(const Vector2 & screenPosition)
{
	//マウスカーソルの座標をウィンドウ座標に変換
	Vector2 window(screenPosition.x, mViewport.height - screenPosition.y);

	//ビューポート変換の逆変換をおこなう
	Vector3 position;
	position.x = (((window.x - mViewport.x)  * 2.0f / mViewport.width) - 1.0f);
	position.y = (((window.y - mViewport.y)  * 2.0f / mViewport.height) - 1.0f);

	//透視変換行列の逆変換をおこなう
	position.x /= mProjectionMatrix.m[0][0];
	position.y /= mProjectionMatrix.m[1][1];
	position.z = -1.0f;

	//視野変換行列の逆行列を求める
	Matrix4 invView(mViewMatrix);
	invView.inverseFast();

	//レイの位置を設定
	//レイの方向を計算
	Vector3 dir = invView.transformNormal(position);
	Ray ray(invView.getPosition(),dir.normalize());
	return ray;
}

//メッシュ描画
void Renderer::render(const MeshRenderDesc & desc)
{
	//ブレンド方法の設定
	setBlendFunc(desc.blendFunc);
	//カラーの設定
	glColor4fv((GLfloat*)&desc.color);
	//透視変換行列の設定
	glMatrixMode(GL_PROJECTION);
	glLoadMatrixf((GLfloat*)&mProjectionMatrix);
	//視野変換行列の設定
	glMatrixMode(GL_MODELVIEW);
	glLoadMatrixf((GLfloat*)&mViewMatrix);
	//ライトの座標設定
	GLfloat lightPosition[] = {
		mLight.position.x,
		mLight.position.y,
		mLight.position.z,
		0.0f
	};
	glEnable(GL_LIGHTING);
	glLightfv(GL_LIGHT0,GL_POSITION, lightPosition);
	glEnable(GL_LIGHT0);
	//メッシュ描画
	glMultMatrixf((GLfloat*)&desc.matrix);
	gsDrawMesh(desc.meshID);
}

void Renderer::render(const AnimationRenderDesc & desc)
{	
	//ブレンド方法の設定
	setBlendFunc(desc.blendFunc);
	//カラーの設定
	glColor4fv((GLfloat*)&desc.color);
	//透視変換行列の設定
	glMatrixMode(GL_PROJECTION);
	glLoadMatrixf((GLfloat*)&mProjectionMatrix);
	//視野変換行列の設定
	glMatrixMode(GL_MODELVIEW);
	glLoadMatrixf((GLfloat*)&mViewMatrix);
	//ライトの座標設定
	GLfloat lightPosition[] = {
		mLight.position.x,
		mLight.position.y,
		mLight.position.z,
		0.0f
	};
	glEnable(GL_LIGHTING);
	glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
	glEnable(GL_LIGHT0);
	//メッシュ描画
	glMultMatrixf((GLfloat*)&desc.matrix);
	gsMeshDrawSkin(gsGetMesh(desc.meshID), desc.animation);
}

void Renderer::render(const SkinnedMeshRenderDesc & desc)
{
	gsBeginShader(desc.shaderID);

	GSvector3 light_position_eye = mLight.position * mViewMatrix;
	gsSetShaderParam3f("u_lightPositionEye", &light_position_eye);
	gsSetShaderParam4f("u_lightAmbient", &mLight.ambient);
	gsSetShaderParam4f("u_lightDiffuse", &mLight.diffuse);
	gsSetShaderParam4f("u_lightSpecular", &mLight.specular);


	gsSetShaderParamMatrix4("u_matWorld", &desc.matrix);
	gsSetShaderParamMatrix4("u_matView", &mViewMatrix);
	gsSetShaderParamMatrix4("u_matProjection", &mProjectionMatrix);
	gsSetShaderParamTexture("u_baseMap", 0);
	gsSetShaderParamTexture("u_normalMap", 1);
	gsSetShaderParam4f("u_color",&desc.color);
	gsSetShaderParamArrayMatrix4("gs_BoneMatrices", gsGetSkeletonNumBones(desc.meshID), desc.animation);

	//メッシュ描画
	gsMeshDrawEx(gsGetMesh(desc.meshID));
	gsEndShader();
}

void Renderer::render(const BillBoardRenderDesc & desc)
{
	//各種レンダリングモード退避
	glPushAttrib(GL_ENABLE_BIT | GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//面カリングを無効か
	glDisable(GL_CULL_FACE);
	//ライティングをオフ
	glDisable(GL_LIGHTING);

	//ブレンド方法を設定
	setBlendFunc(desc.blendFunc);

	//ビルボード処理用の変換行列を作成
	Matrix4 matBillboard(mViewMatrix);
	matBillboard.setPosition(Vector3(0, 0, 0));
	matBillboard.transpose();

	//モデリング変換行列の作成
	Matrix4 matModel(desc.matrix);
	matModel.setPosition(Vector3(0, 0, 0));
	matModel *= matBillboard;
	matModel.setPosition(desc.matrix.getPosition());

	//モデルビュー変換行列の作成
	Matrix4 matModelView(matModel * mViewMatrix);

	//透視変換行列の設定
	glMatrixMode(GL_PROJECTION);
	glLoadMatrixf((GLfloat*)&mProjectionMatrix);
	//視野変換行列の設定
	glMatrixMode(GL_MODELVIEW);
	glLoadMatrixf((GLfloat*)&matModelView);

	//テクスチャのレンダリングを行う
	renderTexture(desc.textureID, desc.rect, desc.srcRect, desc.color);

	//レンダリングモード復帰
	glPopAttrib();
}

void Renderer::render(const SpriteRenderDesc & desc)
{
	// 各種レンダリングモードの退避
	glPushAttrib(GL_ENABLE_BIT | GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// 面カリングを無効にする
	glDisable(GL_CULL_FACE);
	// ライティングを無効にする
	glDisable(GL_LIGHTING);
	// ｚバッファを無効にする
	glDisable(GL_DEPTH_TEST);

	// ブレンド方法の設定
	setBlendFunc(desc.blendFunc);

	//gsDrawSprite2D(desc.textureID,);
	// 透視変換行列の設定
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, mViewport.width, mViewport.height, 0);

	// モデルビュー変換行列の設定
	glMatrixMode(GL_MODELVIEW);

	glPushMatrix();
	// 変換行列の初期化
	glLoadIdentity();
	//glLoadMatrixf();
	//glLoadMatrixf((GLfloat*)&desc.matrix);

	glMultMatrixf(desc.matrix);
	// 中心位置の補正を行う
	glTranslatef(-desc.center.x, -desc.center.y, 0);

	// テクスチャのレンダリングを行う
	renderTexture(desc.textureID, desc.color);

	glPopMatrix();
	// 透視変換行列を復帰
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	// モデルビュー変換行列に設定
	glMatrixMode(GL_MODELVIEW);
	// レンダリングモードの復帰
	glPopAttrib();
}

void Renderer::render(const SpriteRectRenderDesc & desc)
{
	// 各種レンダリングモードの退避
	glPushAttrib(GL_ENABLE_BIT | GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// 面カリングを無効にする
	glDisable(GL_CULL_FACE);
	// ライティングを無効にする
	glDisable(GL_LIGHTING);
	// ｚバッファを無効にする
	glDisable(GL_DEPTH_TEST);

	// ブレンド方法の設定
	setBlendFunc(desc.blendFunc);

	// 透視変換行列の設定
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, mViewport.width, mViewport.height, 0);

	// モデルビュー変換行列の設定
	glMatrixMode(GL_MODELVIEW);
	glLoadMatrixf((GLfloat*)&desc.matrix);

	// 中心位置の補正を行う
	glTranslatef(-desc.center.x, -desc.center.y, 0);

	// スプライトの幅と高さを求める
	float width = desc.srcRect.right - desc.srcRect.left;
	float height = desc.srcRect.bottom - desc.srcRect.top;
	Rect rect(0, 0, width, height);

	// テクスチャのレンダリングを行う
	renderTexture(desc.textureID, rect, desc.srcRect, desc.color);

	// レンダリングモードの復帰
	glPopAttrib();
}

void Renderer::render(const NumberSpriteRenderDesc & desc)
{
	std::ostringstream stream;
	stream << std::fixed << std::setprecision(desc.decimal);
	//小数点を表示する場合は点の数も追加
	GSuint digit=desc.digit;
	digit += desc.decimal == 0 ? 0 : 1;
	//0で埋める              　　　　　　　　　右寄せ
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
		//位置をずらす .なら半分
		x = desc.size.x;
		x *= istoken ? 0.5f : 1.0f;
		mat.translate(x, 0, 0);
	}
}

void Renderer::render(const StringRenderDesc & desc)
{
	//文字色の設定
	glColor4fv((GLfloat*)&desc.color);

	//文字フォントの設定
	gsFontParameter(
		desc.font.code,
		desc.font.size,
		desc.font.name.c_str());

	//表示位置の設定
	gsTextPos(desc.position.x, desc.position.y);

	//文字列の描画
	gsDrawText(desc.string.c_str());
}

void Renderer::render(const RectangleRenderDesc & desc)
{
	//各種レンダリングモード退避
	glPushAttrib(GL_ENABLE_BIT | GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//面カリングを無効
	glDisable(GL_CULL_FACE);
	//ライティングをオフ
	glDisable(GL_LIGHTING);
	//ｚバッファ無効に
	glDisable(GL_DEPTH_TEST);

	//ブレンド方法の設定
	setBlendFunc(desc.blendFunc);

	//透視変換行列の設定
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, mViewport.width, mViewport.height, 0);

	//四角形の描画
	glBegin(GL_QUADS);
	glColor4fv((GLfloat*)&desc.color);
	glVertex2f(desc.rect.left, desc.rect.top);
	glVertex2f(desc.rect.left, desc.rect.bottom);
	glVertex2f(desc.rect.right, desc.rect.bottom);
	glVertex2f(desc.rect.right, desc.rect.top);
	glEnd();

	//レンダリングモード復帰
	glPopAttrib();
}
void Renderer::render(const OctreeRenderDesc & desc)
{
	//ブレンド方法の設定
	setBlendFunc(desc.blendFunc);
	//カラーの設定
	glColor4fv((GLfloat*)&desc.color);
	//透視変換行列の設定
	glMatrixMode(GL_PROJECTION);
	glLoadMatrixf((GLfloat*)&mProjectionMatrix);
	//視野変換行列の設定
	glMatrixMode(GL_MODELVIEW);
	glLoadMatrixf((GLfloat*)&mViewMatrix);
	//ライトの座標設定
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
}

void Renderer::render(const SkyBoxRenderDesc & desc)
{
	//ブレンド方法の設定
	setBlendFunc(desc.blendFunc);
	//カラーの設定
	glColor4fv((GLfloat*)&desc.color);
	//透視変換行列の設定
	glMatrixMode(GL_PROJECTION);
	glLoadMatrixf((GLfloat*)&mProjectionMatrix);
	//視野変換行列の設定
	glMatrixMode(GL_MODELVIEW);
	glLoadMatrixf((GLfloat*)&mViewMatrix);
	//ライトの座標設定
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
}
//ブレンド関数の設定
void Renderer::setBlendFunc(BlendFunc blendFunc)
{
	//ブレンドを有効に
	glEnable(GL_BLEND);

	switch (blendFunc)
	{
	case BlendFunc::NONE://ブレンドなし
		glDepthMask(GL_TRUE);
		glDisable(GL_BLEND);
		break;
	case BlendFunc::DEFAULT://デフォルト
		glDepthMask(GL_TRUE);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		break;
	case BlendFunc::ALPHA://アルファ値による半透明
		glDepthMask(GL_FALSE);
		glBlendFunc(GL_ONE, GL_ONE_MINUS_SRC_COLOR);
		break;
	case BlendFunc::ADD://加算による半透明
		glDepthMask(GL_FALSE);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE);
		break;
	case BlendFunc::SUB://減算による半透明
		glDepthMask(GL_FALSE);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE);
		break;
	default:
		break;
	}
}

void Renderer::renderTexture(ResourceID id, const Color4 & color)
{// テクスチャをバインドする
	gsBindTexture(id);

	// バインド中のテクスチャの幅と高さを取得
	GLsizei texWidth;
	glGetTexLevelParameteriv(GL_TEXTURE_2D, 0, GL_TEXTURE_WIDTH, &texWidth);
	GLsizei	texHeight;
	glGetTexLevelParameteriv(GL_TEXTURE_2D, 0, GL_TEXTURE_HEIGHT, &texHeight);
	// スプライトの幅と高さを求める
	GSrect rect(0,0,texWidth,texHeight);
	// テクスチャ座標の計算を行う
	GSrect texCoord(0.0f,0.0f,1.0f,1.0f);

	// 四角形の描画
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

	// テクスチャを無効にする
	glBindTexture(GL_TEXTURE_2D, 0);
}

void Renderer::renderTexture(ResourceID id, const Rect & rect, const Rect & srcRect, const Color4 & color)
{
	// テクスチャをバインドする
	gsBindTexture(id);

	// バインド中のテクスチャの幅と高さを取得
	GLsizei texWidth;
	glGetTexLevelParameteriv(GL_TEXTURE_2D, 0, GL_TEXTURE_WIDTH, &texWidth);
	GLsizei	texHeight;
	glGetTexLevelParameteriv(GL_TEXTURE_2D, 0, GL_TEXTURE_HEIGHT, &texHeight);

	// テクスチャ座標の計算を行う
	GSrect texCoord(
		srcRect.left / texWidth,
		srcRect.top / texHeight,
		srcRect.right / texWidth,
		srcRect.bottom / texHeight);

	// 四角形の描画
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

	// テクスチャを無効にする
	glBindTexture(GL_TEXTURE_2D, 0);
}
