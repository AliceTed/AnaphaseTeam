#include "BasicShapes.h"

// �R���X�g���N�^
BasicShapeMesh::BasicShapeMesh(unsigned int vertexCount, unsigned int indexCount, GLenum primitive) :
	vertices_(vertexCount), indices_(indexCount), primitive_(primitive) {
}

// �C���f�b�N�X�̎擾
void* BasicShapeMesh::indices() const {
	return (void*)&indices_[0];
}

// ���_���W�̎擾
void* BasicShapeMesh::positions() const {
	return (void*)&vertices_[0].m_Position;
}

// �@���x�N�g���̎擾
void* BasicShapeMesh::normals() const {
	return (void*)&vertices_[0].normal;
}

// �e�N�X�`�����W�̎擾
void* BasicShapeMesh::texcoords() const {
	return (void*)&vertices_[0].texcoord;
}

// �ڃx�N�g���̎擾
void* BasicShapeMesh::tangents() const {
	return (void*)&vertices_[0].tangent;
}

// �]�@���x�N�g���̎擾
void* BasicShapeMesh::binormals() const {
	return (void*)&vertices_[0].binormal;
}

// ���_�f�[�^�̊Ԋu���擾
int BasicShapeMesh::vertexStride() const {
	return sizeof( vertices_[0] );
}

// �C���f�b�N�X�f�[�^�̃T�C�Y���擾
int BasicShapeMesh::indexSize() const {
	return sizeof( indices_[0] );
}

// ���_���̎擾
int BasicShapeMesh::vertexCount() const {
	return (int)vertices_.size();
}

// �C���f�b�N�X���̎擾
int BasicShapeMesh::indexCount() const {
	return (int)indices_.size();
}

// �C���f�b�N�X�^�C�v�̎擾
GLenum BasicShapeMesh::indexType() const {
	return GL_UNSIGNED_SHORT;
}

// �v���~�e�B�u�^�C�v�̎擾
GLenum BasicShapeMesh::primitive() const {
	return primitive_;
}

// ��]�̂̃C���f�b�N�X���쐬
void BasicShapeMesh::revolutionizeIndices(IndexBuffer& indices, int slices, int stacks) {
	unsigned int idx = 0;
	unsigned short index = 0;
	for (int i=0; i < slices; ++i) {
		for (int j=0; j < stacks; ++j) {
			indices[idx++] = index;
			indices[idx++] = index + 1;
			indices[idx++] = index + stacks + 2;
			indices[idx++] = index + stacks + 1;
			++index;
		}
		++index;
	}
}

// �`��
void BasicShapeMesh::draw(const VertexAttribute& attribute) const {
	// ���_�f�[�^�̐ݒ�
	if (attribute.m_Position != -1) {
		glEnableVertexAttribArray(attribute.m_Position);
		glVertexAttribPointer(attribute.m_Position, 3, GL_FLOAT, GL_FALSE, vertexStride(), positions());
	}
	if (attribute.normal != -1) {
		glEnableVertexAttribArray(attribute.normal);
		glVertexAttribPointer(attribute.normal, 3, GL_FLOAT, GL_FALSE, vertexStride(), normals());
	}
	if (attribute.texcoord != -1) {
		glEnableVertexAttribArray(attribute.texcoord);
		glVertexAttribPointer(attribute.texcoord, 2, GL_FLOAT, GL_FALSE, vertexStride(), texcoords());
	}
	if (attribute.tangent != -1) {
		glEnableVertexAttribArray(attribute.tangent);
		glVertexAttribPointer(attribute.tangent, 3, GL_FLOAT, GL_FALSE, vertexStride(), tangents());
	}
	if (attribute.binormal != -1) {
		glEnableVertexAttribArray(attribute.binormal);
		glVertexAttribPointer(attribute.binormal, 3, GL_FLOAT, GL_FALSE, vertexStride(), binormals());
	}
	// �`��
	glDrawElements(primitive(), indexCount(), indexType(), indices());
	// ���_�f�[�^�𖳌��ɂ���
	if (attribute.m_Position != -1) glDisableVertexAttribArray(attribute.m_Position);
	if (attribute.normal   != -1) glDisableVertexAttribArray(attribute.normal);
	if (attribute.texcoord != -1) glDisableVertexAttribArray(attribute.texcoord);
	if (attribute.tangent  != -1) glDisableVertexAttribArray(attribute.tangent);
	if (attribute.binormal != -1) glDisableVertexAttribArray(attribute.binormal);
}

// �`��
void BasicShapeMesh::draw() const {
	glPushAttrib(GL_ENABLE_BIT);
	glEnable(GL_NORMALIZE);
	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, vertexStride(), positions());
	glEnableClientState(GL_NORMAL_ARRAY);
	glNormalPointer(GL_FLOAT, vertexStride(), normals());
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	glTexCoordPointer(2, GL_FLOAT, vertexStride(), texcoords());
	glEnableVertexAttribArray(14);
	glVertexAttribPointer(14, 3, GL_FLOAT, GL_FALSE, vertexStride(), binormals());
	glEnableVertexAttribArray(15);
	glVertexAttribPointer(15, 3, GL_FLOAT, GL_FALSE, vertexStride(), tangents());
	glDrawElements(primitive(), indexCount(), indexType(), indices());
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_NORMAL_ARRAY);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	glDisableVertexAttribArray(14);
	glDisableVertexAttribArray(15);
	glPopAttrib();
}

// ���̃��b�V���R���X�g���N�^
SphereMesh::SphereMesh(float radius, int slices, int stacks)
	: BasicShapeMesh((slices+1) * (stacks+1), slices * stacks * 4) {
	// ���_�f�[�^�̍쐬
	int idx = 0;
	for (int i = 0; i <= slices; ++i) {
		float ti = (float)i / slices;
		GSmatrix4 ry;
		ry.identity().rotateY(LERP(ti, 0.0f, 360.0f));
		for (int j = 0; j <= stacks; ++j) {
			float tj = (float)j / stacks;
			float angle = LERP(tj,90.0f, -90.0f);
			float vx = gsCos(angle);
			float vy = gsSin(angle);
			vertices_[idx].m_Position = GSvector3(vx * radius, vy * radius, 0.0) * ry;
			vertices_[idx].normal = GSvector3(vx, vy, 0.0) * ry;
			vertices_[idx].tangent = GSvector3(0.0f, 0.0f, -1.0f) * ry;
			vertices_[idx].binormal = vertices_[idx].tangent.cross(vertices_[idx].normal) * ry;
			vertices_[idx].texcoord = GSvector2(LERP(ti, 0.0, 1.0), LERP(tj, 0.0, 1.0));
			++idx;
		}
	}
	// �C���f�b�N�X�̍쐬
	revolutionizeIndices(indices_, slices, stacks);
}

// �g�[���X���b�V���R���X�g���N�^
TorusMesh::TorusMesh(float innerRadius, float outerRadius, int sides, int rings)
	: BasicShapeMesh((sides+1) * (rings+1), sides * rings * 4) {
	// ���_�f�[�^�̍쐬
	float radius = (outerRadius - innerRadius) / 2.0f;
	float x = (outerRadius + innerRadius) / 2.0f;
	int idx = 0;
	for (int i = 0; i <= rings; ++i) {
		float ti = (float)i / rings;
		GSmatrix4 ry;
		ry.identity().rotateY(LERP(ti, 0.0f, 360.0f)).rotateX(90.0f);
		for (int j = 0; j <= sides; ++j) {
			float tj = (float)j / sides;
			float angle = LERP(tj, 180.0f, -180.0f);
			float vx = gsCos(angle);
			float vy = gsSin(angle);
			vertices_[idx].m_Position = GSvector3(vx * radius + x, vy * radius, 0.0f) * ry;
			vertices_[idx].normal = GSvector3(vx, vy, 0.0f) * ry;
			vertices_[idx].tangent = GSvector3(0.0f, 0.0f, -1.0f) * ry;
			vertices_[idx].binormal = vertices_[idx].tangent.cross(vertices_[idx].normal) * ry;
			vertices_[idx].texcoord = GSvector2(LERP(ti, 0.0f, 1.0f), LERP(tj, 0.0f, 1.0f));
			++idx;
		}
	}
	// �C���f�b�N�X�̍쐬
	revolutionizeIndices(indices_, sides, rings);
}

// �~�����b�V���R���X�g���N�^
CylinderMesh::CylinderMesh(float radius, float height, int sides)
	: BasicShapeMesh((sides+1)*6, sides*5*4) {
	static const Vertex v[] = {
		{ GSvector3(0.0, 0.5, 0.0), GSvector3(0.0, 1.0, 0.0), GSvector2(0.0, 0.0), GSvector3(0.0, 0.0, -1.0), GSvector3( 1.0, 0.0, 0.0) },
		{ GSvector3(1.0, 0.5, 0.0), GSvector3(0.0, 1.0, 0.0), GSvector2(0.0, 1.0), GSvector3(0.0, 0.0, -1.0), GSvector3( 1.0, 0.0, 0.0) },
		{ GSvector3(1.0, 0.5, 0.0), GSvector3(1.0, 0.0, 0.0), GSvector2(0.0, 0.0), GSvector3(0.0, 0.0, -1.0), GSvector3( 0.0,-1.0, 0.0) },
		{ GSvector3(1.0,-0.5, 0.0), GSvector3(1.0, 0.0, 0.0), GSvector2(0.0, 1.0), GSvector3(0.0, 0.0, -1.0), GSvector3( 0.0,-1.0, 0.0) },
		{ GSvector3(1.0,-0.5, 0.0), GSvector3(0.0,-1.0, 0.0), GSvector2(0.0, 1.0), GSvector3(0.0, 0.0, -1.0), GSvector3(-1.0, 0.0, 0.0) },
		{ GSvector3(0.0,-0.5, 0.0), GSvector3(0.0,-1.0, 0.0), GSvector2(0.0, 0.0), GSvector3(0.0, 0.0, -1.0), GSvector3(-1.0, 0.0, 0.0) },
	};
	// ���_�f�[�^�̍쐬
	int idx = 0;
	for (int i = 0; i <= sides; ++i) {
		float ti = (float)i / sides;
		GSmatrix4 ry;
		ry.identity().rotateY(LERP(ti, 0.0f, 360.0f));
		for (int j = 0; j < ARRAY_LENGTH(v); ++j) {
			GSvector3 m_Position( v[j].m_Position.x * radius, v[j].m_Position.y * height, v[j].m_Position.z );
			vertices_[idx].m_Position = m_Position * ry;
			vertices_[idx].normal = v[j].normal * ry;
			vertices_[idx].tangent = v[j].tangent * ry;
			vertices_[idx].binormal = v[j].binormal * ry;
			vertices_[idx].texcoord = GSvector2(LERP(ti, 0.0, 1.0), v[j].texcoord.y);
			++idx;
		}
	}
	// �C���f�b�N�X�̍쐬
	revolutionizeIndices(indices_, sides, ARRAY_LENGTH(v)-1);
}

// �����̃��b�V���R���X�g���N�^
BoxMesh::BoxMesh(float width, float height, float depth)
	: BasicShapeMesh(24, 24)  {
	static const Vertex v[] = {
		// ����
		{ GSvector3(-0.5f, 0.5f, 0.5f), GSvector3( 0.0f, 0.0f, 1.0f), GSvector2(0.0f,0.0f), GSvector3( 1.0f, 0.0f, 0.0f), GSvector3( 0.0f,-1.0f, 0.0f) },
		{ GSvector3(-0.5f,-0.5f, 0.5f), GSvector3( 0.0f, 0.0f, 1.0f), GSvector2(0.0f,1.0f), GSvector3( 1.0f, 0.0f, 0.0f), GSvector3( 0.0f,-1.0f, 0.0f) },
		{ GSvector3( 0.5f,-0.5f, 0.5f), GSvector3( 0.0f, 0.0f, 1.0f), GSvector2(1.0f,1.0f), GSvector3( 1.0f, 0.0f, 0.0f), GSvector3( 0.0f,-1.0f, 0.0f) },
		{ GSvector3( 0.5f, 0.5f, 0.5f), GSvector3( 0.0f, 0.0f, 1.0f), GSvector2(1.0f,0.0f), GSvector3( 1.0f, 0.0f, 0.0f), GSvector3( 0.0f,-1.0f, 0.0f) },
		// �E
		{ GSvector3( 0.5f, 0.5f, 0.5f), GSvector3( 1.0f, 0.0f, 0.0f), GSvector2(0.0f,0.0f), GSvector3( 0.0f, 0.0f,-1.0f), GSvector3( 0.0f,-1.0f, 0.0f) },
		{ GSvector3( 0.5f,-0.5f, 0.5f), GSvector3( 1.0f, 0.0f, 0.0f), GSvector2(0.0f,1.0f), GSvector3( 0.0f, 0.0f,-1.0f), GSvector3( 0.0f,-1.0f, 0.0f) },
		{ GSvector3( 0.5f,-0.5f,-0.5f), GSvector3( 1.0f, 0.0f, 0.0f), GSvector2(1.0f,1.0f), GSvector3( 0.0f, 0.0f,-1.0f), GSvector3( 0.0f,-1.0f, 0.0f) },
		{ GSvector3( 0.5f, 0.5f,-0.5f), GSvector3( 1.0f, 0.0f, 0.0f), GSvector2(1.0f,0.0f), GSvector3( 0.0f, 0.0f,-1.0f), GSvector3( 0.0f,-1.0f, 0.0f) },
		// �w��
		{ GSvector3( 0.5f, 0.5f,-0.5f), GSvector3( 0.0f, 0.0f,-1.0f), GSvector2(0.0f,0.0f), GSvector3(-1.0f, 0.0f, 0.0f), GSvector3( 0.0,-1.0f, 0.0f) },
		{ GSvector3( 0.5f,-0.5f,-0.5f), GSvector3( 0.0f, 0.0f,-1.0f), GSvector2(0.0f,1.0f), GSvector3(-1.0f, 0.0f, 0.0f), GSvector3( 0.0,-1.0f, 0.0f) },
		{ GSvector3(-0.5f,-0.5f,-0.5f), GSvector3( 0.0f, 0.0f,-1.0f), GSvector2(1.0f,1.0f), GSvector3(-1.0f, 0.0f, 0.0f), GSvector3( 0.0,-1.0f, 0.0f) },
		{ GSvector3(-0.5f, 0.5f,-0.5f), GSvector3( 0.0f, 0.0f,-1.0f), GSvector2(1.0f,0.0f), GSvector3(-1.0f, 0.0f, 0.0f), GSvector3( 0.0,-1.0f, 0.0f) },
		// ��
		{ GSvector3(-0.5f, 0.5f,-0.5f), GSvector3(-1.0f, 0.0f, 0.0f), GSvector2(0.0f,0.0f), GSvector3( 1.0f, 0.0f, 0.0f), GSvector3( 0.0f,-1.0f, 0.0f) },
		{ GSvector3(-0.5f,-0.5f,-0.5f), GSvector3(-1.0f, 0.0f, 0.0f), GSvector2(0.0f,1.0f), GSvector3( 1.0f, 0.0f, 0.0f), GSvector3( 0.0f,-1.0f, 0.0f) },
		{ GSvector3(-0.5f,-0.5f, 0.5f), GSvector3(-1.0f, 0.0f, 0.0f), GSvector2(1.0f,1.0f), GSvector3( 1.0f, 0.0f, 0.0f), GSvector3( 0.0f,-1.0f, 0.0f) },
		{ GSvector3(-0.5f, 0.5f, 0.5f), GSvector3(-1.0f, 0.0f, 0.0f), GSvector2(1.0f,0.0f), GSvector3( 1.0f, 0.0f, 0.0f), GSvector3( 0.0f,-1.0f, 0.0f) },
		// ��
		{ GSvector3(-0.5f, 0.5f,-0.5f), GSvector3( 0.0f, 1.0f, 0.0f), GSvector2(0.0f,0.0f), GSvector3( 1.0f, 0.0f, 0.0f), GSvector3( 0.0f, 0.0f, 1.0f) },
		{ GSvector3(-0.5f, 0.5f, 0.5f), GSvector3( 0.0f, 1.0f, 0.0f), GSvector2(0.0f,1.0f), GSvector3( 1.0f, 0.0f, 0.0f), GSvector3( 0.0f, 0.0f, 1.0f) },
		{ GSvector3( 0.5f, 0.5f, 0.5f), GSvector3( 0.0f, 1.0f, 0.0f), GSvector2(1.0f,1.0f), GSvector3( 1.0f, 0.0f, 0.0f), GSvector3( 0.0f, 0.0f, 1.0f) },
		{ GSvector3( 0.5f, 0.5f,-0.5f), GSvector3( 0.0f, 1.0f, 0.0f), GSvector2(1.0f,0.0f), GSvector3( 1.0f, 0.0f, 0.0f), GSvector3( 0.0f, 0.0f, 1.0f) },
		// ��
		{ GSvector3(-0.5f,-0.5f, 0.5f), GSvector3( 0.0f,-1.0f, 0.0f), GSvector2(0.0f,0.0f), GSvector3( 1.0f, 0.0f, 0.0f), GSvector3( 0.0f, 0.0f,-1.0f) },
		{ GSvector3(-0.5f,-0.5f,-0.5f), GSvector3( 0.0f,-1.0f, 0.0f), GSvector2(0.0f,1.0f), GSvector3( 1.0f, 0.0f, 0.0f), GSvector3( 0.0f, 0.0f,-1.0f) },
		{ GSvector3( 0.5f,-0.5f,-0.5f), GSvector3( 0.0f,-1.0f, 0.0f), GSvector2(1.0f,1.0f), GSvector3( 1.0f, 0.0f, 0.0f), GSvector3( 0.0f, 0.0f,-1.0f) },
		{ GSvector3( 0.5f,-0.5f, 0.5f), GSvector3( 0.0f,-1.0f, 0.0f), GSvector2(1.0f,0.0f), GSvector3( 1.0f, 0.0f, 0.0f), GSvector3( 0.0f, 0.0f,-1.0f) },
	};
	// ���_�f�[�^�̍쐬
	for (VertexBuffer::size_type i=0; i < vertices_.size(); ++i) {
		vertices_[i] = v[i];
		vertices_[i].m_Position = GSvector3(v[i].m_Position.x * width, v[i].m_Position.y * height, v[i].m_Position.z * depth); 
	}
	// �C���f�b�N�X�̍쐬
	for (IndexBuffer::size_type i=0; i < indices_.size(); ++i) {
		indices_[i] = (unsigned short)i;
	}
}

// end of file

