#ifndef EFFECT_GL_H_
#define EFFECT_GL_H_

#include <gslib.h>
#include <opengl_ext.h>
#include <string>
#include <fstream>
#include <vector>
#include <stdexcept>

// GLSL�V�F�[�_�[�N���X
class GLSLShader {
public:
	// �R���X�g���N�^
	GLSLShader(GLenum type, const std::string& fileName) :
		type_(type),
		shader_(0) {
		shader_ = glCreateShader(type);
		complie(fileName);
	}
	// �f�X�g���N�^
	~GLSLShader() {
		glDeleteShader(shader_);
	}
	// �V�F�[�_�[�^�C�v�̎擾
	GLenum type() const {
		return type_;
	}
	// �V�F�[�_�[�̎擾
	GLuint shader() const {
		return shader_;
	}

private:
	// �V�F�[�_�[�̃R���p�C��
	void complie(const std::string& fileName) {
		// �V�F�[�_�[�t�@�C���̓ǂݍ���
		const std::vector<char> program(load(fileName));
		// �V�F�[�_�[�̃R���p�C��
		const GLchar* string = &program[0];
		const GLint size = program.size();
		glShaderSource(shader_, 1, &string, &size);
		glCompileShader(shader_);
		// �R���p�C���G���[�̃`�F�b�N
		GLint compiled = 0;
		glGetShaderiv(shader_, GL_COMPILE_STATUS, &compiled);
		if (compiled == GL_FALSE) {
			// �R���p�C���G���[���o��
			GLint length = 0;
			glGetShaderiv(shader_, GL_INFO_LOG_LENGTH, &length);
			std::vector<char> log(length);
			glGetShaderInfoLog(shader_, (GLsizei)log.size(), 0, &log[0]);
			glDeleteShader(shader_);
			shader_ = 0;
			OutputDebugStringA("glsl comple error\n");
			OutputDebugStringA(fileName.c_str());
			OutputDebugStringA("\n");
			OutputDebugStringA(&log[0]);
			throw std::runtime_error("glsl comple error " + fileName);
		}
	}
	// �V�F�[�_�[�t�@�C���̓ǂݍ���
	std::vector<char> load(const std::string& fileName) {
		std::ifstream file(fileName, std::ios::binary);
		if (!file) throw std::runtime_error("can not open " + fileName);
		// �t�@�C���T�C�Y�̎擾
		file.seekg(0, std::ios_base::end);
		std::size_t size = (std::size_t)file.tellg();
		file.seekg(0, std::ios_base::beg);
		// �V�F�[�_�[�t�@�C�����o�b�t�@�ɓǂݍ���
		std::vector<char> program(size);
		file.read(&program[0], size);
		return program;
	}
private:
	// �R�s�[�֎~
	GLSLShader(const GLSLShader& other);
	GLSLShader& operator = (const GLSLShader& other);
private:
	// �V�F�[�_�[�^�C�v
	GLenum type_;
	// �V�F�[�_�[
	GLuint shader_;
};

// GLSL�v���O�����N���X
class GLSLProgram {
public:
	// �R���X�g���N�^
	GLSLProgram() : program_(0) {
		program_ = glCreateProgram();
	}
	// �f�X�g���N�^
	~GLSLProgram() {
		glDeleteProgram(program_);
	}
	// �V�F�[�_�[�̃R���p�C��
	void compleShader(GLenum type, const std::string& fileName) {
		// �V�F�[�_�[�̍쐬
		const GLSLShader shader(type, fileName);
		// �V�F�[�_�[���A�^�b�`
		glAttachShader(program_, shader.shader());
	}
	// �V�F�[�_�[�̃����N
	void link() {
		glLinkProgram(program_);
		// �����N�G���[�̊m�F
		GLint linked = 0;
		glGetProgramiv(program_, GL_LINK_STATUS, &linked);
		if (linked == GL_FALSE) {
			// �����N�G���[�̏o��
			GLint length = 0;
			glGetProgramiv(program_, GL_INFO_LOG_LENGTH, &length);
			std::vector<char> log(length);
			glGetProgramInfoLog(program_, (GLsizei)log.size(), 0, &log[0]);
			OutputDebugStringA("glsl link error\n");
			OutputDebugStringA(&log[0]);
			throw std::runtime_error("glsl link error");
		}
	}
	// �v���O�����̊J�n
	void begin() {
		glUseProgram(program_);
	}
	// �v���O�����̏I��
	void end() {
		glUseProgram(0);
	}
	// �V�F�[�_�[�p�����[�^�̎擾
	GLint uniform(const std::string& name) const {
		return glGetUniformLocation(program_, name.c_str());
	}
	// �A�g���r���[�g�̎擾
	GLint attribute(const std::string& name) const {
		return glGetAttribLocation(program_, name.c_str());
	}

private:
	// �R�s�[�֎~
	GLSLProgram(const GLSLProgram& other);
	GLSLProgram& operator = (const GLSLProgram& other);
private:
	// GLSL�v���O����
	GLuint program_;
};

// OpenGL�p�ȈՃG�t�F�N�g�N���X
class EffectGL {
public:
	// �R���X�g���N�^
	EffectGL(const std::string& vertexShaderFileName, const std::string& fragmentShaderFileName) {
		program_.compleShader(GL_VERTEX_SHADER, vertexShaderFileName);
		program_.compleShader(GL_FRAGMENT_SHADER, fragmentShaderFileName);
		program_.link();
	}
	// �A�g���r���[�g�̎擾
	GLint attribute(const std::string& name) const {
		return program_.attribute(name);
	}
	// �V�F�[�_�[��L���ɂ���
	void begin() {
		program_.begin();
	}
	// �V�F�[�_�[�𖳌��ɂ���
	void end() {
		program_.end();
	}
	// float�̃p�����[�^��ݒ�
	void setParameter(const std::string& name, float s) {
		glUniform1f(program_.uniform(name), s);
	}
	// Vector2�̃p�����[�^��ݒ�
	void setParameter(const std::string& name, const GSvector2& v) {
		glUniform2f(program_.uniform(name), v.x, v.y);
	}
	// Vector3�̃p�����[�^��ݒ�
	void setParameter(const std::string& name, const GSvector3& v) {
		glUniform3f(program_.uniform(name), v.x, v.y, v.z);
	}
	// Color4�̃p�����[�^��ݒ�
	void setParameter(const std::string& name, const GScolor4& v)
	{
		glUniform4f(program_.uniform(name), v.r, v.g, v.b, v.a);
	}
	// Matrix4�̃p�����[�^��ݒ�
	void setParameter(const std::string& name, const GSmatrix4& m) {
		glUniformMatrix4fv(program_.uniform(name), 1, GL_FALSE, m);
	}
	// �e�N�X�`���̃p�����[�^��ݒ�
	void setTexture(const std::string& name, GLuint unit) {
		glUniform1i(program_.uniform(name), unit);
	}

private:
	// �R�s�[�֎~
	EffectGL(const EffectGL& other);
	EffectGL& operator = (const EffectGL& other);
private:
	// GLSL�v���O����
	GLSLProgram program_;
};

#endif

// end of file
