#pragma once

struct Vector2 {
	float x = 0;
	float y = 0;
};

float GetDistanceBetweenPoints(Vector2 startPos, Vector2 endPos) {
	return sqrt((pow(endPos.x - startPos.x, 2) + pow(endPos.y - startPos.y, 2)));
}