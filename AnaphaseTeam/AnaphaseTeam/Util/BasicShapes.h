#ifndef _BASIC_SHAPES_H_
#define _BASIC_SHAPES_H_

#include <gslib.h>
#include <vector>

// ��{�`�󃁃b�V���N���X
class BasicShapeMesh {
public:
	// ���_�A�g���r���[�g
	struct VertexAttribute {
		GLint m_Position;		// ���_���W
		GLint normal;		// �@���x�N�g��
		GLint texcoord;		// �e�N�X�`�����W
		GLint tangent;		// �ڃx�N�g��
		GLint binormal;		// �]�@���x�N�g��
		VertexAttribute() :
			m_Position(-1),
			normal(-1),
			texcoord(-1),
			tangent(-1),
			binormal(-1) {
		}
	};
public:
	// �R���X�g���N�^
	BasicShapeMesh(unsigned int vertexCount, unsigned int indexCount, GLenum primitive = GL_QUADS);
	// ���z�f�X�g���N�^
	virtual ~BasicShapeMesh() {}
	// �C���f�b�N�X�̎擾
	void* indices() const;
	// ���_���W�̎擾
	void* positions() const;
	// �@���x�N�g���̎擾
	void* normals() const;
	// �e�N�X�`�����W�̎擾
	void* texcoords() const;
	// �ڃx�N�g���̎擾
	void* tangents() const;
	// �]�@���x�N�g���̎擾
	void* binormals() const;
	// ���_�f�[�^�̊Ԋu���擾
	int vertexStride() const;
	// �C���f�b�N�X�f�[�^�̃T�C�Y���擾
	int indexSize() const;
	// ���_���̎擾
	int vertexCount() const;
	// �C���f�b�N�X���̎擾
	int indexCount() const;
	// �C���f�b�N�o�b�t�@�^�C�v�̎擾
	GLenum indexType() const;
	// �v���~�e�B�u�^�C�v�̎擾
	GLenum primitive() const;
	// �`��
	void draw(const VertexAttribute& attribute) const;
	// �`��
	void draw() const;

protected:
	// ���_�f�[�^�^
	struct Vertex {
		GSvector3 m_Position;	// ���_���W
		GSvector3 normal;	// �@���x�N�g��
		GSvector2 texcoord;	// �e�N�X�`�����W
		GSvector3 tangent;	// �ڃx�N�g��
		GSvector3 binormal;	// �]�@���x�N�g��
	};
	// ���_�o�b�t�@�^
	typedef std::vector<Vertex>	VertexBuffer;
	// �C���f�b�N�X�o�b�t�@�^
	typedef std::vector<unsigned short> IndexBuffer;

	// ��]�̂̃C���f�b�N�X���쐬����
	static void revolutionizeIndices(IndexBuffer& indices, int slices, int stacks);

protected:
	// ���_�o�b�t�@
	VertexBuffer vertices_;
	// �C���f�b�N�X�o�b�t�@
	IndexBuffer indices_;
	// �v���~�e�B�u�^�C�v
	GLenum primitive_;
};

// ���̃��b�V��
class SphereMesh : public BasicShapeMesh {
public:
	// �R���X�g���N�^
	SphereMesh(float radius=1.0f, int slices=32, int stacks=16);
};

// �g�[���X���b�V��
class TorusMesh : public BasicShapeMesh {
public:
	// �R���X�g���N�^
	TorusMesh(float innerRadius=0.25f, float outerRadius=1.0f, int sides=32, int rings=32);
};

// �~�����b�V��
class CylinderMesh : public BasicShapeMesh {
public:
	// �R���X�g���N�^
	CylinderMesh(float radius=1.0f, float height=1.0f, int sides=32);
};

// �����̃��b�V��
class BoxMesh : public BasicShapeMesh {
public:
	// �R���X�g���N�^
	BoxMesh(float width=1.0f, float height=1.0f, float depth=1.0f);
};

#endif

// end of file
