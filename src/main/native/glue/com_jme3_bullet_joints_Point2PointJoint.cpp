/*
 * Copyright (c) 2009-2012 jMonkeyEngine
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 * * Redistributions of source code must retain the above copyright
 *   notice, this list of conditions and the following disclaimer.
 *
 * * Redistributions in binary form must reproduce the above copyright
 *   notice, this list of conditions and the following disclaimer in the
 *   documentation and/or other materials provided with the distribution.
 *
 * * Neither the name of 'jMonkeyEngine' nor the names of its contributors
 *   may be used to endorse or promote products derived from this software
 *   without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
 * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/*
 * Author: Normen Hansen
 */
#include "com_jme3_bullet_joints_Point2PointJoint.h"
#include "jmeBulletUtil.h"

/*
 * Class:     com_jme3_bullet_joints_Point2PointJoint
 * Method:    createJoint
 * Signature: (JJLcom/jme3/math/Vector3f;Lcom/jme3/math/Vector3f;)J
 */
JNIEXPORT jlong JNICALL Java_com_jme3_bullet_joints_Point2PointJoint_createJoint
(JNIEnv *env, jobject object, jlong bodyIdA, jlong bodyIdB, jobject pivotA,
        jobject pivotB) {
    jmeClasses::initJavaClasses(env);

    btRigidBody *pBodyA = reinterpret_cast<btRigidBody *> (bodyIdA);
    NULL_CHK(env, pBodyA, "Rigid body A does not exist.", 0)
    btAssert(pBodyA->getInternalType() & btCollisionObject::CO_RIGID_BODY);

    btRigidBody *pBodyB = reinterpret_cast<btRigidBody *> (bodyIdB);
    NULL_CHK(env, pBodyB, "Rigid body B does not exist.", 0)
    btAssert(pBodyB->getInternalType() & btCollisionObject::CO_RIGID_BODY);

    NULL_CHK(env, pivotA, "The pivotA vector does not exist.", 0)
    btVector3 pivotInA;
    jmeBulletUtil::convert(env, pivotA, &pivotInA);

    NULL_CHK(env, pivotB, "The pivotB vector does not exist.", 0)
    btVector3 pivotInB;
    jmeBulletUtil::convert(env, pivotB, &pivotInB);

    btPoint2PointConstraint *pJoint = new btPoint2PointConstraint(*pBodyA,
            *pBodyB, pivotInA, pivotInB);

    return reinterpret_cast<jlong> (pJoint);
}

/*
 * Class:     com_jme3_bullet_joints_Point2PointJoint
 * Method:    createJoint1
 * Signature: (JLcom/jme3/math/Vector3f;)J
 */
JNIEXPORT jlong JNICALL Java_com_jme3_bullet_joints_Point2PointJoint_createJoint1
(JNIEnv *env, jobject object, jlong bodyIdA, jobject pivotA) {
    jmeClasses::initJavaClasses(env);

    btRigidBody *pBodyA = reinterpret_cast<btRigidBody *> (bodyIdA);
    NULL_CHK(env, pBodyA, "Rigid body A does not exist.", 0)
    btAssert(pBodyA->getInternalType() & btCollisionObject::CO_RIGID_BODY);

    NULL_CHK(env, pivotA, "The pivotA vector does not exist.", 0)
    btVector3 pivotInA;
    jmeBulletUtil::convert(env, pivotA, &pivotInA);

    btPoint2PointConstraint *pJoint
            = new btPoint2PointConstraint(*pBodyA, pivotInA);

    return reinterpret_cast<jlong> (pJoint);
}

/*
 * Class:     com_jme3_bullet_joints_Point2PointJoint
 * Method:    getDamping
 * Signature: (J)F
 */
JNIEXPORT jfloat JNICALL Java_com_jme3_bullet_joints_Point2PointJoint_getDamping
(JNIEnv *env, jobject object, jlong jointId) {
    btPoint2PointConstraint *pJoint
            = reinterpret_cast<btPoint2PointConstraint *> (jointId);
    NULL_CHK(env, pJoint, "The btPoint2PointConstraint does not exist.", 0)
    btAssert(pJoint->getConstraintType() == POINT2POINT_CONSTRAINT_TYPE);

    return pJoint->m_setting.m_damping;
}

/*
 * Class:     com_jme3_bullet_joints_Point2PointJoint
 * Method:    getImpulseClamp
 * Signature: (J)F
 */
JNIEXPORT jfloat JNICALL Java_com_jme3_bullet_joints_Point2PointJoint_getImpulseClamp
(JNIEnv *env, jobject object, jlong jointId) {
    btPoint2PointConstraint *pJoint
            = reinterpret_cast<btPoint2PointConstraint *> (jointId);
    NULL_CHK(env, pJoint, "The btPoint2PointConstraint does not exist.", 0)
    btAssert(pJoint->getConstraintType() == POINT2POINT_CONSTRAINT_TYPE);

    return pJoint->m_setting.m_impulseClamp;
}

/*
 * Class:     com_jme3_bullet_joints_Point2PointJoint
 * Method:    getTau
 * Signature: (J)F
 */
JNIEXPORT jfloat JNICALL Java_com_jme3_bullet_joints_Point2PointJoint_getTau
(JNIEnv *env, jobject object, jlong jointId) {
    btPoint2PointConstraint *pJoint
            = reinterpret_cast<btPoint2PointConstraint *> (jointId);
    NULL_CHK(env, pJoint, "The btPoint2PointConstraint does not exist.", 0)
    btAssert(pJoint->getConstraintType() == POINT2POINT_CONSTRAINT_TYPE);

    return pJoint->m_setting.m_tau;
}

/*
 * Class:     com_jme3_bullet_joints_Point2PointJoint
 * Method:    setDamping
 * Signature: (JF)V
 */
JNIEXPORT void JNICALL Java_com_jme3_bullet_joints_Point2PointJoint_setDamping
(JNIEnv *env, jobject object, jlong jointId, jfloat damping) {
    btPoint2PointConstraint *pJoint
            = reinterpret_cast<btPoint2PointConstraint *> (jointId);
    NULL_CHK(env, pJoint, "The btPoint2PointConstraint does not exist.",)
    btAssert(pJoint->getConstraintType() == POINT2POINT_CONSTRAINT_TYPE);

    pJoint->m_setting.m_damping = damping;
}

/*
 * Class:     com_jme3_bullet_joints_Point2PointJoint
 * Method:    setImpulseClamp
 * Signature: (JF)V
 */
JNIEXPORT void JNICALL Java_com_jme3_bullet_joints_Point2PointJoint_setImpulseClamp
(JNIEnv *env, jobject object, jlong jointId, jfloat clamp) {
    btPoint2PointConstraint *pJoint
            = reinterpret_cast<btPoint2PointConstraint *> (jointId);
    NULL_CHK(env, pJoint, "The btPoint2PointConstraint does not exist.",)
    btAssert(pJoint->getConstraintType() == POINT2POINT_CONSTRAINT_TYPE);

    pJoint->m_setting.m_impulseClamp = clamp;
}

/*
 * Class:     com_jme3_bullet_joints_Point2PointJoint
 * Method:    setTau
 * Signature: (JF)V
 */
JNIEXPORT void JNICALL Java_com_jme3_bullet_joints_Point2PointJoint_setTau
(JNIEnv *env, jobject object, jlong jointId, jfloat tau) {
    btPoint2PointConstraint *pJoint
            = reinterpret_cast<btPoint2PointConstraint *> (jointId);
    NULL_CHK(env, pJoint, "The btPoint2PointConstraint does not exist.",)
    btAssert(pJoint->getConstraintType() == POINT2POINT_CONSTRAINT_TYPE);

    pJoint->m_setting.m_tau = tau;
}
