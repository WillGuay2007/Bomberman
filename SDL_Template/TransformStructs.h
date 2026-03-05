#pragma once

struct Vector2 {
	float x;
	float y;
	Vector2(float _x, float _y) : x(_x), y(_y) {}
};

struct Size {
	float width;
	float height;
	Size(float _w, float _h) : width(_w), height(_h) {}
};

struct GridPosition {
	int column;
	int row;
	GridPosition(int _column, int _row) : column(_column), row(_row) {}
};