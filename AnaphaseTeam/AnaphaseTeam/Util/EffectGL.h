#ifndef EFFECT_GL_H_
#define EFFECT_GL_H_

#include <gslib.h>
#include <opengl_ext.h>
#include <string>
#include <fstream>
#include <vector>
#include <stdexcept>

// GLSLシェーダークラス
class GLSLShader {
public:
	// コンストラクタ
	GLSLShader(GLenum type, const std::string& fileName) :
		type_(type),
		shader_(0) {
		shader_ = glCreateShader(type);
		complie(fileName);
	}
	// デストラクタ
	~GLSLShader() {
		glDeleteShader(shader_);
	}
	// シェーダータイプの取得
	GLenum type() const {
		return type_;
	}
	// シェーダーの取得
	GLuint shader() const {
		return shader_;
	}

private:
	// シェーダーのコンパイル
	void complie(const std::string& fileName) {
		// シェーダーファイルの読み込み
		const std::vector<char> program(load(fileName));
		// シェーダーのコンパイル
		const GLchar* string = &program[0];
		const GLint size = program.size();
		glShaderSource(shader_, 1, &string, &size);
		glCompileShader(shader_);
		// コンパイルエラーのチェック
		GLint compiled = 0;
		glGetShaderiv(shader_, GL_COMPILE_STATUS, &compiled);
		if (compiled == GL_FALSE) {
			// コンパイルエラーを出力
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
	// シェーダーファイルの読み込み
	std::vector<char> load(const std::string& fileName) {
		std::ifstream file(fileName, std::ios::binary);
		if (!file) throw std::runtime_error("can not open " + fileName);
		// ファイルサイズの取得
		file.seekg(0, std::ios_base::end);
		std::size_t size = (std::size_t)file.tellg();
		file.seekg(0, std::ios_base::beg);
		// シェーダーファイルをバッファに読み込む
		std::vector<char> program(size);
		file.read(&program[0], size);
		return program;
	}
private:
	// コピー禁止
	GLSLShader(const GLSLShader& other);
	GLSLShader& operator = (const GLSLShader& other);
private:
	// シェーダータイプ
	GLenum type_;
	// シェーダー
	GLuint shader_;
};

// GLSLプログラムクラス
class GLSLProgram {
public:
	// コンストラクタ
	GLSLProgram() : program_(0) {
		program_ = glCreateProgram();
	}
	// デストラクタ
	~GLSLProgram() {
		glDeleteProgram(program_);
	}
	// シェーダーのコンパイル
	void compleShader(GLenum type, const std::string& fileName) {
		// シェーダーの作成
		const GLSLShader shader(type, fileName);
		// シェーダーをアタッチ
		glAttachShader(program_, shader.shader());
	}
	// シェーダーのリンク
	void link() {
		glLinkProgram(program_);
		// リンクエラーの確認
		GLint linked = 0;
		glGetProgramiv(program_, GL_LINK_STATUS, &linked);
		if (linked == GL_FALSE) {
			// リンクエラーの出力
			GLint length = 0;
			glGetProgramiv(program_, GL_INFO_LOG_LENGTH, &length);
			std::vector<char> log(length);
			glGetProgramInfoLog(program_, (GLsizei)log.size(), 0, &log[0]);
			OutputDebugStringA("glsl link error\n");
			OutputDebugStringA(&log[0]);
			throw std::runtime_error("glsl link error");
		}
	}
	// プログラムの開始
	void begin() {
		glUseProgram(program_);
	}
	// プログラムの終了
	void end() {
		glUseProgram(0);
	}
	// シェーダーパラメータの取得
	GLint uniform(const std::string& name) const {
		return glGetUniformLocation(program_, name.c_str());
	}
	// アトリビュートの取得
	GLint attribute(const std::string& name) const {
		return glGetAttribLocation(program_, name.c_str());
	}

private:
	// コピー禁止
	GLSLProgram(const GLSLProgram& other);
	GLSLProgram& operator = (const GLSLProgram& other);
private:
	// GLSLプログラム
	GLuint program_;
};

// OpenGL用簡易エフェクトクラス
class EffectGL {
public:
	// コンストラクタ
	EffectGL(const std::string& vertexShaderFileName, const std::string& fragmentShaderFileName) {
		program_.compleShader(GL_VERTEX_SHADER, vertexShaderFileName);
		program_.compleShader(GL_FRAGMENT_SHADER, fragmentShaderFileName);
		program_.link();
	}
	// アトリビュートの取得
	GLint attribute(const std::string& name) const {
		return program_.attribute(name);
	}
	// シェーダーを有効にする
	void begin() {
		program_.begin();
	}
	// シェーダーを無効にする
	void end() {
		program_.end();
	}
	// floatのパラメータを設定
	void setParameter(const std::string& name, float s) {
		glUniform1f(program_.uniform(name), s);
	}
	// Vector2のパラメータを設定
	void setParameter(const std::string& name, const GSvector2& v) {
		glUniform2f(program_.uniform(name), v.x, v.y);
	}
	// Vector3のパラメータを設定
	void setParameter(const std::string& name, const GSvector3& v) {
		glUniform3f(program_.uniform(name), v.x, v.y, v.z);
	}
	// Color4のパラメータを設定
	void setParameter(const std::string& name, const GScolor4& v)
	{
		glUniform4f(program_.uniform(name), v.r, v.g, v.b, v.a);
	}
	// Matrix4のパラメータを設定
	void setParameter(const std::string& name, const GSmatrix4& m) {
		glUniformMatrix4fv(program_.uniform(name), 1, GL_FALSE, m);
	}
	// テクスチャのパラメータを設定
	void setTexture(const std::string& name, GLuint unit) {
		glUniform1i(program_.uniform(name), unit);
	}

private:
	// コピー禁止
	EffectGL(const EffectGL& other);
	EffectGL& operator = (const EffectGL& other);
private:
	// GLSLプログラム
	GLSLProgram program_;
};

#endif

// end of file
