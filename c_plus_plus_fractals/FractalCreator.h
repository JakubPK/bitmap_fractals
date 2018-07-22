#pragma once
#include <string>
#include <cstdint>
#include <memory>
#include <math.h>
#include "Zoom.h"
#include "Mandelbrot.h"
#include "Bitmap.h"
#include "ZoomList.h"


class FractalCreator {
private:
	int m_width;
	int m_height;
	std::unique_ptr<int[]> m_histogram;
	std::unique_ptr<int[]> m_fractal;
	Bitmap m_bitmap;
	ZoomList m_zoomList;
	int m_total{ 0 };

public:
	FractalCreator(int width, int height);

	virtual ~FractalCreator();

	void calculateIteration();

	void calculateTotalIterations();

	void drawFractal();

	void addZoom(const Zoom& zoom);

	void writeBitmap(std::string name);
};
