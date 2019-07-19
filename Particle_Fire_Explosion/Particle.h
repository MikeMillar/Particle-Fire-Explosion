#ifndef PARTICLE_H
#define PARTICLE_H

namespace sf {
	struct Particle {
		double m_x, m_y;
		Particle();
		virtual ~Particle();
		void update();
		double m_xSpeed;
		double m_ySpeed;
	};
}
#endif
