/*
 * Copyright (c) 2009-2015 jMonkeyEngine
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
 * Author: Dokthar
 */
#include "com_jme3_bullet_SoftBodyWorldInfo.h"
#include "jmeBulletUtil.h"
#include "BulletSoftBody/btSoftBody.h"

/*
 * Class:     com_jme3_bullet_SoftBodyWorldInfo
 * Method:    createSoftBodyWorldInfo
 * Signature: ()J
 */
JNIEXPORT jlong JNICALL Java_com_jme3_bullet_SoftBodyWorldInfo_createSoftBodyWorldInfo
(JNIEnv *env, jobject object) {
    jmeClasses::initJavaClasses(env);
    btSoftBodyWorldInfo *pInfo = new btSoftBodyWorldInfo();
    return reinterpret_cast<jlong> (pInfo);
}

/*
 * Class:     com_jme3_bullet_SoftBodyWorldInfo
 * Method:    getAirDensity
 * Signature: (J)F
 */
JNIEXPORT jfloat JNICALL Java_com_jme3_bullet_SoftBodyWorldInfo_getAirDensity
(JNIEnv *env, jobject object, jlong worldId) {
    const btSoftBodyWorldInfo * const pInfo
            = reinterpret_cast<btSoftBodyWorldInfo *> (worldId);
    NULL_CHK(env, pInfo, "The btSoftBodyWorldInfo does not exist.", 0);

    return pInfo->air_density;
}

/*
 * Class:     com_jme3_bullet_SoftBodyWorldInfo
 * Method:    getGravity
 * Signature: (JLcom/jme3/math/Vector3f;)V
 */
JNIEXPORT void JNICALL Java_com_jme3_bullet_SoftBodyWorldInfo_getGravity
(JNIEnv *env, jobject object, jlong worldId, jobject storeVector) {
    const btSoftBodyWorldInfo * const pInfo
            = reinterpret_cast<btSoftBodyWorldInfo *> (worldId);
    NULL_CHK(env, pInfo, "The btSoftBodyWorldInfo does not exist.",);

    NULL_CHK(env, storeVector, "The store vector does not exist.",);
    jmeBulletUtil::convert(env, &pInfo->m_gravity, storeVector);
}

/*
 * Class:     com_jme3_bullet_SoftBodyWorldInfo
 * Method:    getMaxDisplacement
 * Signature: (J)F
 */
JNIEXPORT jfloat JNICALL Java_com_jme3_bullet_SoftBodyWorldInfo_getMaxDisplacement
(JNIEnv *env, jobject object, jlong infoId) {
    const btSoftBodyWorldInfo * const pInfo
            = reinterpret_cast<btSoftBodyWorldInfo *> (infoId);
    NULL_CHK(env, pInfo, "The btSoftBodyWorldInfo does not exist.", 0);

    return pInfo->m_maxDisplacement;
}

/*
 * Class:     com_jme3_bullet_SoftBodyWorldInfo
 * Method:    getWaterDensity
 * Signature: (J)F
 */
JNIEXPORT jfloat JNICALL Java_com_jme3_bullet_SoftBodyWorldInfo_getWaterDensity
(JNIEnv *env, jobject object, jlong infoId) {
    const btSoftBodyWorldInfo * const pInfo
            = reinterpret_cast<btSoftBodyWorldInfo *> (infoId);
    NULL_CHK(env, pInfo, "The btSoftBodyWorldInfo does not exist.", 0);

    return pInfo->water_density;
}

/*
 * Class:     com_jme3_bullet_SoftBodyWorldInfo
 * Method:    getWaterNormal
 * Signature: (JLcom/jme3/math/Vector3f;)V
 */
JNIEXPORT void JNICALL Java_com_jme3_bullet_SoftBodyWorldInfo_getWaterNormal
(JNIEnv *env, jobject object, jlong infoId, jobject storeVector) {
    const btSoftBodyWorldInfo * const pInfo
            = reinterpret_cast<btSoftBodyWorldInfo *> (infoId);
    NULL_CHK(env, pInfo, "The btSoftBodyWorldInfo does not exist.",);

    NULL_CHK(env, storeVector, "The store vector does not exist.",);
    jmeBulletUtil::convert(env, &pInfo->water_normal, storeVector);
}

/*
 * Class:     com_jme3_bullet_SoftBodyWorldInfo
 * Method:    getWaterOffset
 * Signature: (J)F
 */
JNIEXPORT jfloat JNICALL Java_com_jme3_bullet_SoftBodyWorldInfo_getWaterOffset
(JNIEnv *env, jobject object, jlong infoId) {
    const btSoftBodyWorldInfo * const pInfo
            = reinterpret_cast<btSoftBodyWorldInfo *> (infoId);
    NULL_CHK(env, pInfo, "The btSoftBodyWorldInfo does not exist.", 0);

    return pInfo->water_offset;
}

/*
 * Class:     com_jme3_bullet_SoftBodyWorldInfo
 * Method:    setAirDensity
 * Signature: (JF)V
 */
JNIEXPORT void JNICALL Java_com_jme3_bullet_SoftBodyWorldInfo_setAirDensity
(JNIEnv *env, jobject object, jlong infoId, jfloat value) {
    btSoftBodyWorldInfo * const pInfo
            = reinterpret_cast<btSoftBodyWorldInfo *> (infoId);
    NULL_CHK(env, pInfo, "The btSoftBodyWorldInfo does not exist.",);

    pInfo->air_density = value;
}

/*
 * Class:     com_jme3_bullet_SoftBodyWorldInfo
 * Method:    setGravity
 * Signature: (JLcom/jme3/math/Vector3f;)V
 */
JNIEXPORT void JNICALL Java_com_jme3_bullet_SoftBodyWorldInfo_setGravity
(JNIEnv *env, jobject object, jlong infoId, jobject gravityVector) {
    btSoftBodyWorldInfo * const pInfo
            = reinterpret_cast<btSoftBodyWorldInfo *> (infoId);
    NULL_CHK(env, pInfo, "The btSoftBodyWorldInfo does not exist.",);

    NULL_CHK(env, gravityVector, "The gravity vector does not exist.",);
    jmeBulletUtil::convert(env, gravityVector, &pInfo->m_gravity);
}

/*
 * Class:     com_jme3_bullet_SoftBodyWorldInfo
 * Method:    setMaxDisplacement
 * Signature: (JF)V
 */
JNIEXPORT void JNICALL Java_com_jme3_bullet_SoftBodyWorldInfo_setMaxDisplacement
(JNIEnv *env, jobject object, jlong infoId, jfloat value) {
    btSoftBodyWorldInfo * const pInfo
            = reinterpret_cast<btSoftBodyWorldInfo *> (infoId);
    NULL_CHK(env, pInfo, "The btSoftBodyWorldInfo does not exist.",);

    pInfo->m_maxDisplacement = value;
}

/*
 * Class:     com_jme3_bullet_SoftBodyWorldInfo
 * Method:    setSoftBodyWorldInfo
 * Signature: (JJ)V
 */
JNIEXPORT void JNICALL Java_com_jme3_bullet_SoftBodyWorldInfo_setSoftBodyWorldInfo
(JNIEnv *env, jobject object, jlong destId, jlong sourceId) {
    btSoftBodyWorldInfo * const pDest
            = reinterpret_cast<btSoftBodyWorldInfo *> (destId);
    NULL_CHK(env, pDest, "The target btSoftBodyWorldInfo does not exist.",);

    btSoftBodyWorldInfo *pSource
            = reinterpret_cast<btSoftBodyWorldInfo *> (sourceId);
    NULL_CHK(env, pSource, "The source btSoftBodyWorldInfo does not exist.",);

    if (pDest != pSource) {
        *pDest = *pSource;
    }
}

/*
 * Class:     com_jme3_bullet_SoftBodyWorldInfo
 * Method:    setWaterDensity
 * Signature: (JF)V
 */
JNIEXPORT void JNICALL Java_com_jme3_bullet_SoftBodyWorldInfo_setWaterDensity
(JNIEnv *env, jobject object, jlong infoId, jfloat value) {
    btSoftBodyWorldInfo * const pInfo
            = reinterpret_cast<btSoftBodyWorldInfo *> (infoId);
    NULL_CHK(env, pInfo, "The btSoftBodyWorldInfo does not exist.",);

    pInfo->water_density = value;
}

/*
 * Class:     com_jme3_bullet_SoftBodyWorldInfo
 * Method:    setWaterNormal
 * Signature: (JLcom/jme3/math/Vector3f;)V
 */
JNIEXPORT void JNICALL Java_com_jme3_bullet_SoftBodyWorldInfo_setWaterNormal
(JNIEnv *env, jobject object, jlong infoId, jobject normalVector) {
    btSoftBodyWorldInfo * const pInfo
            = reinterpret_cast<btSoftBodyWorldInfo *> (infoId);
    NULL_CHK(env, pInfo, "The btSoftBodyWorldInfo does not exist.",);

    NULL_CHK(env, normalVector, "The normal vector does not exist.",);
    jmeBulletUtil::convert(env, normalVector, &pInfo->water_normal);
}

/*
 * Class:     com_jme3_bullet_SoftBodyWorldInfo
 * Method:    setWaterOffset
 * Signature: (JF)V
 */
JNIEXPORT void JNICALL Java_com_jme3_bullet_SoftBodyWorldInfo_setWaterOffset
(JNIEnv *env, jobject object, jlong infoId, jfloat value) {
    btSoftBodyWorldInfo * const pInfo
            = reinterpret_cast<btSoftBodyWorldInfo *> (infoId);
    NULL_CHK(env, pInfo, "The btSoftBodyWorldInfo does not exist.",);

    pInfo->water_offset = value;
}
