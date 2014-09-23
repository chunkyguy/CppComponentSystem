//
//  HS_Camera.h
//  HitSoccer
//
//  Created by Sid on 15/07/14.
//  Copyright (c) 2014 whackylabs. All rights reserved.
//

#ifndef __HitSoccer__HS_Camera__
#define __HitSoccer__HS_Camera__
#include <GLKit/GLKMath.h>

/** Camera object */
class Camera {
public:

    /** Create an default Camera */
    Camera();

    /** Apply a zoom 
     * @param z Zoom factor.
     */
    void SetZoom(const float z);
    
    /** Apply a pan to the camera 
     * @param pan A pan offset from center
     */
    void SetPan(const GLKVector2 &pan);
    
    /** Set the focus area of the camera.
     * The end result may not be exactly the supplied value due to zoom and 
     * pan factors
     * @param area A focus area
     */
    void SetFocusArea(const GLKVector2 &area);

    /** Set the eye point 
     * Eye point means where do you want to camera to focus.
     * @param e The eye point.
     */
    void SetEye(const GLKVector3 e);
    
    /** Set the center of the camera point
     * Center and Up points are used to calculate the viewing direction
     * @param c A center point.
     */
    void SetCenter(const GLKVector3 c);

    /** Set the up direction of the camera.
     * Center and Up points are used to calculate the viewing direction
     * @param u An up direction.
     */
    void SetUp(const GLKVector3 u);

    /** Get the projection matrix for the current state of camera.
     * @return Projection matrix.
     */
    GLKMatrix4 GetProjectionMatrix() const;
    
    /** Get the view matrix for the current state of camera.
     * @return View matrix
     */
    GLKMatrix4 GetViewMatrix() const;
    
private:
    void UpdateProjection();
    void UpdateView();

    GLKVector2 area_;
    GLKVector3 eye_, center_, up_;
    GLKMatrix4 projectionMatrix_;
    GLKMatrix4 viewMatrix_;
    float zoom_;
    GLKVector2 pan_;
};


inline void Camera::SetZoom(const float z)
{
    zoom_ = z;
    UpdateProjection();
}

inline void Camera::SetPan(const GLKVector2 &pan)
{
    pan_ = pan;
    UpdateProjection();
}

inline void Camera::SetFocusArea(const GLKVector2 &area)
{
    area_ = area;
    UpdateProjection();
}

inline void Camera::SetEye(const GLKVector3 e)
{
    eye_ = e;
    UpdateView();
}

inline void Camera::SetCenter(const GLKVector3 c)
{
    center_ = c;
    UpdateView();
}

inline void Camera::SetUp(const GLKVector3 u)
{
    up_ = u;
    UpdateView();
}

inline GLKMatrix4 Camera::GetProjectionMatrix() const
{
    return projectionMatrix_;
}

inline GLKMatrix4 Camera::GetViewMatrix() const
{
    return viewMatrix_;
}

#endif /* defined(__HitSoccer__HS_Camera__) */
