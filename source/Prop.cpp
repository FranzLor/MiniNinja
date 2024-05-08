#include "Prop.h"


Prop::Prop(Vector2 propPos, Texture2D propTex)
	: texture(propTex),
	worldPosition(propPos),
	scale(0.0f) {



}


Prop::~Prop() {
	UnloadTexture(texture);
}



