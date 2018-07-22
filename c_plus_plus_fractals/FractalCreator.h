#pragma once
#include <string>
#include <cstdint>
#include <memory>
#include <math.h>
#include <vector>
#include "Zoom.h"
#include "Mandelbrot.h"
#include "Bitmap.h"
#include "ZoomList.h"
#include "RGB.h"


class FractalCreator {
private:
	int m_width;
	int m_height;
	std::unique_ptr<int[]> m_histogram;
	std::unique_ptr<int[]> m_fractal;
	Bitmap m_bitmap;
	ZoomList m_zoomList;
	int m_total{ 0 };
	std::vector<int> m_ranges;
	std::vector<RGB> m_colors;
	std::vector<int> m_rangeTotal;

	void calculateIteration();
	void calculateTotalIterations();
	void drawFractal();
	void writeBitmap(std::string name);

public:
	FractalCreator(int width, int height);
	virtual ~FractalCreator();
	void addRange(double rangeEnd, const RGB& rgb);
	void addZoom(const Zoom& zoom);
	void run(std::string name);
};
