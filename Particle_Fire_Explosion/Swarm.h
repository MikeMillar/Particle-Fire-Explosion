#ifndef SWARM_H
#define SWARM_H
#include "Particle.h"

namespace sf {
	class Swarm {
	private:
		Particle* m_pParticles;

	public:
		const static int NPARTICLES = 5000;

	public:
		Swarm();
		~Swarm();
		const Particle* const getParticles() { return m_pParticles; }
	};
}



#endif