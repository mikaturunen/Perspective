#ifndef PERSPECTIVE_HPP
#define PERSPECTIVE_HPP

// NOTE : depends on opengl headers and libraries, naturally. :)

namespace Utilities {
	/*!
		Sets perspective. Used to replace gluPerspective.
		@param fov
			Field of view.
		@param aspectRatio
			Aspect ratio of the screen; generally speaking width of screen divided by height.
		@param zNear
			Z-near clipping plane.
		@param zFar
			Z-far clipping plane.
	*/
	void SetPerspective(const float &fov, const float &aspectRatio, const float &zNear, 
		const float &zFar) {
		const float PI = 3.14159265f;
		const float halfH = tan(fov / 180 * PI) * zNear;
		const float halfW = halfH * aspectRatio;

		glFrustum( -halfW, halfW, -halfH, halfH, zNear, zFar );
	}
};

#endif