#include "Swarm.h"

namespace sf {
	Swarm::Swarm() {
		m_pParticles = new Particle[NPARTICLES];
	}

	Swarm::~Swarm() {
		delete[] m_pParticles;
	}
	void Swarm::update() {
		for (int i = 0; i < sf::Swarm::NPARTICLES; i++) {
			m_pParticles[i].update();
		}
	}
}