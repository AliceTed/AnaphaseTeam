#pragma once

#include "../renderer/define/ResourceID.h"
#include "../renderer/define/Type.h"
#include <string>

struct ViewportDesc;
struct LightDesc;
struct MeshRenderDesc;
struct AnimationRenderDesc;
struct SkinnedMeshRenderDesc;
struct BillboardRenderDesc;
struct SpriteRenderDesc;
struct StringRenderDesc;
struct RectangleRenderDesc;
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
	//���C�g�̐ݒ�
	virtual void light(const LightDesc& desc) = 0;
	//���C�̌v�Z���s��
	virtual Ray caluclateRay(const Vector2&screenPosition) = 0;
	//���b�V���̕`��
	virtual void render(const MeshRenderDesc& desc) = 0;
	//�A�j���[�V�������郁�b�V���̕`��
	virtual void render(const AnimationRenderDesc& desc) = 0;
	//�V�F�[�_���g�p�����A�j���[�V�����̕`��
	virtual void render(const SkinnedMeshRenderDesc& desc) = 0;
	//�r���{�[�h�̕`��
	virtual void render(const BillboardRenderDesc& desc) = 0;
	//�X�v���C�g�`��
	virtual void render(const SpriteRenderDesc& desc) = 0;
	//������̕`��
	virtual void render(const StringRenderDesc& desc) = 0;
	//��`�̕`��
	virtual void render(const RectangleRenderDesc& desc) = 0;
};