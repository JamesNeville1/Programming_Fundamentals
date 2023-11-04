#pragma once

struct Vector2 {
	float x;
	float y;
};

float GetDistanceBetweenPoints(Vector2 startPos, Vector2 endPos) {
	return sqrt((pow(endPos.x - startPos.x, 2) + pow(endPos.y - startPos.y, 2)));
}