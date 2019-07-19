#include "Swarm.h"

namespace sf {
	Swarm::Swarm(): lastTime(0) {
		m_pParticles = new Particle[NPARTICLES];
	}

	Swarm::~Swarm() {
		delete[] m_pParticles;
	}
	void Swarm::update(int elapsed) {
		int interval = elapsed - lastTime;
		for (int i = 0; i < sf::Swarm::NPARTICLES; i++) {
			m_pParticles[i].update(interval);
		}

		lastTime = elapsed;
	}
}