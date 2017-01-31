#pragma once

#include "../renderer/define/ResourceID.h"
#include "../renderer/define/Type.h"
#include <string>

struct ViewportDesc;
struct LightDesc;
struct MeshRenderDesc;
struct AnimationRenderDesc;
struct SkinnedMeshRenderDesc;
struct BillBoardRenderDesc;
struct SpriteRenderDesc;
struct SpriteRectRenderDesc;
struct StringRenderDesc;
struct NumberSpriteRenderDesc;
struct RectangleRenderDesc;
struct OctreeRenderDesc;
struct SkyBoxRenderDesc;
class Ray;
enum class TexColorKey;

//�����_���C���^�t�F�[�X
class IRenderer
{
public:
	//���z�f�X�g���N�^
	virtual ~IRenderer() {};
	//������
	virtual void initialize() = 0;
	//�r���[�|�[�g�ݒ�
	virtual void viewport(const ViewportDesc& desc) = 0;
	//�����ϊ��s��̐ݒ�
	virtual void perspective(float fov, float aspect, float near, float far) = 0;
	//����ϊ��s��̐ݒ�
	virtual void lookAt(const Vector3& eye, const Vector3& at, const Vector3& up) = 0;
	//�r���[�|�[�g�̐ݒ�
	virtual const ViewportDesc& getViewPort() const = 0;
	//�����ϊ��s��̎擾
	virtual const Matrix4& getProjectionMatrix() const = 0;
	//����ϊ��s��̎擾
	virtual const Matrix4& getViewMatrix()  const = 0;
	//���C�g�̎擾
	virtual const LightDesc& getLight()const = 0;

	//���C�g�̐ݒ�
	virtual void light(const LightDesc& desc) = 0;
	//���C�̌v�Z���s��
	virtual Ray caluclateRay(const Vector2&screenPosition) = 0;
	//���b�V���̕`��
	virtual void render(const MeshRenderDesc& desc) = 0;

	//�V�F�[�_���g�p�����A�j���[�V�����̕`��
	virtual void render(const SkinnedMeshRenderDesc& desc) = 0;
	//�r���{�[�h�̕`��
	virtual void render(const BillBoardRenderDesc& desc) = 0;
	//�X�v���C�g�`��
	virtual void render(const SpriteRenderDesc& desc) = 0;
	//�؂���p�X�v���C�g�`��
	virtual void render(const SpriteRectRenderDesc& desc) = 0;
	//�X�v���C�g�ł̐����`��
	virtual void render(const NumberSpriteRenderDesc& desc) = 0;
	//������̕`��
	virtual void render(const StringRenderDesc& desc) = 0;
	//��`�̕`��
	virtual void render(const RectangleRenderDesc& desc) = 0;
	//�I�N�c���[�`��
	virtual void render(const OctreeRenderDesc& desc) = 0;
	//�X�J�C�{�b�N�X�`��
	virtual void render(const SkyBoxRenderDesc& desc) = 0;
};