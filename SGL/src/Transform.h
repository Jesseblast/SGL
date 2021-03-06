

#ifndef _SGL_TRANSFORM_H_
#define _SGL_TRANSFORM_H_

#include "SGLCore.h"
#include "Vector3.h"
#include "Matrix4.h"


namespace SGL {

    class Transform
    {
    public:

        SGL_API Transform(
        );


        SGL_API ~Transform(
        ) noexcept;


        auto SGL_API translate(
            const Vector3<float>& translation
        ) noexcept -> void;


        auto SGL_API setPosition(
            const Vector3<float>& newPosition
        ) noexcept -> void;


        auto SGL_API getPosition(
        ) const noexcept -> Vector3<float>;


        auto SGL_API rotate(
            const Vector3<float>& rotation
        ) noexcept -> void;


        auto SGL_API rotateAround(
            const Vector3<float>& point,
            const Vector3<float>& rotation
        ) noexcept -> void;


        auto SGL_API setRotation(
            const Vector3<float>& newRotation
        ) noexcept -> void;


        auto SGL_API setRotationAround(
            const Vector3<float>& point,
            const Vector3<float>& rotation
        ) noexcept -> void;


        auto SGL_API getRotation(
        ) const noexcept -> Vector3<float>;


        auto SGL_API setLocalScale(
            const Vector3<float>& newScale
        ) noexcept -> void;


        auto SGL_API setLocalScaleAround(
            const Vector3<float>& point,
            const Vector3<float>& newScale
        ) noexcept -> void;


        auto SGL_API getLocalScale(
        ) const noexcept -> Vector3<float>;


        /// <summary>
        /// Get the matrix which represents where the object is in the world space.
        /// </summary>
        /// 
        /// <returns>The world matrix.</returns>
        auto SGL_API getWorldMatrix(
        ) const noexcept -> Matrix4;


    protected:

        // World matrix represents where the object is in the world space.
        Matrix4 m_WorldMatrix4;


    private:
        Vector3<float> m_Position;
        Vector3<float> m_Rotation;
        Vector3<float> m_Scale;
        Vector3<float> m_Pivot; // TODO: pivot point

    };

}  /* namespace SGL */

#endif  /* _SGL_TRANSFORM_H_ */