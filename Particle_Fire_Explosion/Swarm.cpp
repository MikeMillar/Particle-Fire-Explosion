#include "Swarm.h"

namespace sf {
	Swarm::Swarm() {
		m_pParticles = new Particle[NPARTICLES];
	}

	Swarm::~Swarm() {
		delete[] m_pParticles;
	}
}