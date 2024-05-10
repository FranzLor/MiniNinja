#include "Prop.h"

#include <raylib.h>
#include <raymath.h>

Prop::Prop(Vector2 propPos, Texture2D propTex)
	: texture(propTex),
	worldPosition(propPos),
	scale(3.0f) {



}


Prop::~Prop() = default;


void Prop::Render(Vector2 position) {
	Vector2 screenPosition = Vector2Subtract(worldPosition, position);

	DrawTextureEx(texture, screenPosition, 0.0f, scale, WHITE);
}

Rectangle Prop::GetCollisionRec(Vector2 position) const {
	Vector2 screenPosition = Vector2Subtract(worldPosition, position);

	return Rectangle {
		screenPosition.x,
		screenPosition.y,
		static_cast<float>(texture.width) * scale,
		static_cast<float>(texture.height)* scale
	};
}
