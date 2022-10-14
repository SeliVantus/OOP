
#ifndef _EVOLVENT_H_
#define _EVOLVENT_H_


namespace Prog2 {
	struct Point {
		double x;
		double y;
		Point(double x0 = 0, double y0 = 0) :x(x0), y(y0) {};
	};
	class Evolv {
	private:
		Point point;
		double r;


	public:
		Evolv(double rad = 1);
		Evolv& SetPoint(const Point& p0) { point = p0; return *this; }
		Point GetPoint() const { return point; }
		double GetRadius() const { return r; }
		void SetRadius(double);

		double distance(double f) const {return  r * sqrt(1 + f * f); }
		void coordinates(double f) const;  
		double length(double f) const { return r * f * f * 0.5; }
		double curvat(double) const;  
		char* frm() const;

	};

}

#endif