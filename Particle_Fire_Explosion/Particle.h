#ifndef PARTICLE_H
#define PARTICLE_H

namespace sf {
	struct Particle {
		double m_x, m_y, m_speed, m_direction;

	public:
		Particle();
		virtual ~Particle();
		void update(int interval);

	private:
		void init();
	};
}
#endif
