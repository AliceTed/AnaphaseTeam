/**
@file
@brief	�J�����̈ʒu���p�̕ϐ����܂Ƃ߂Ă邾��
@author Yuuho Aritomi
@date	2016/12/08
*/
#pragma once

#include <gslib.h>
#include "transform/Transform.h"

class IRenderer;
class Map;

struct LookAt
{
public:
	/**
	@fn
	@brief �f�t�H���g�R���X�g���N�^
	*/
	LookAt();
	/**
	@fn
	@brief �f�X�g���N�^
	*/
	~LookAt();
	/**
	@fn
	@brief ������
	@param _pos		�����ʒu
	@param _lookPos	�����_
	@param _up		�J�����̏����
	*/
	void init(const GSvector3& _pos, const GSvector3& _lookPos, const GSvector3& _up = GSvector3(0.f, 1.f, 0.f));
	/**
	@fn
	@brief �X�V
	*/
	void update();
	/**
	@fn
	@brief �X�V�i�����_���[�j
	@param _renderer
	*/
	void update(IRenderer* _renderer);
	/**
	@fn
	@brief �J�����̈ړ�
	@param _target	�^�[�Q�b�g
	@param _speed	�ǔ����x
	*/
	void move(const GSvector3 _target, float _speed  = 1);
	/**
	@fn
	@brief �J�����̒����_��ύX
	@param _target	�^�[�Q�b�g
	@param _speed	�ǔ����x
	*/
	void lookAt(const GSvector3& _target, float _speed = 1);
	/**
	@fn
	@brief �e�B���g�E�p��
	@param _pos		���_
	@param _rotate	�p�x
	@param _speed	�ǔ����x
	*/
	void titlePan(const GSvector3& _pos, const GSvector2& _rotate, const GSvector2& _speed = GSvector2(1, 1));
	/**
	@fn
	@brief �h���[
	@param _center		���_
	@param _rotate		�p�x
	@param _distance	���_�ƃJ�����̋���
	@param _speed		�ǔ����x
	*/
	void dolly(const GSvector3& _center, const GSvector2 _rotate, const float _distance, const GSvector2& _speed = GSvector2(1, 1));
	/**
	@fn
	@brief �n�ʂƂ̂����蔻��
	@param _map	�}�b�v
	*/
	void collisionGround(const Map& _map);
	/**
	@fn
	@brief ��ŏ���
	*/
	GSmatrix4 matView();
	/**
	@fn
	@brief ��ŏ���
	*/
	const GSvector3& position();
	/**
	@fn
	@brief ��ŏ���
	*/
	const GSvector3& lookPosition();
	/**
	@fn
	@brief �J�����Ƃ̋���
	@return �J�����Ƃ̋���
	*/
	const float distance(const GSvector3& _other) const;
	/**
	@fn
	@brief �J�����̃g�����X�t�H�[�����擾
	@return �J�����̃g�����X�t�H�[��
	@author Matuo
	*/
	const Transform transform() const;
private:
	//�n�ʂƓ����������H
	bool isHitGround(const Map& _map, GSvector3* _pos);
private:
	//�J�����̈ʒu
	GSvector3 mPos;
	//�J�����̒����_
	GSvector3 mLookPos;
	//�J�����̈ʒu�i�I�t�Z�b�g�j
	GSvector3 mPosOffset;
	//�J�����̒����_�i�I�t�Z�b�g�j
	GSvector3 mLookPosOffset;
	//�J�����̏����
	GSvector3 mUp;
	//���f���r���[�ϊ��s��
	GSmatrix4 mMatView;
	//�h���[�p�i�[�ϐ�
	GSvector2 mRotateDolly;
	//
	GSvector3 mIntersectPos;
};