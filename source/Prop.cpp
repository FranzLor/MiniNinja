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
