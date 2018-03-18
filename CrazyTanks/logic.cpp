#include "logic.h"

Logic::Logic()
{
    m = &GameManager::instance();
}

void Logic::process()
{
    while (!m->stopGame) {
        for(size_t i = 0; i < m->myBullets.size(); i++) {
            if (m->myBullets[i] != nullptr) {
                if (m->myBullets[i]->isShotMade) {
                    BulletAction ba;
                    ba.shot(*m->myBullets[i], m->enemyTanks);
                }
                else {
                    delete m->myBullets[i];
                    m->myBullets[i] = nullptr;
                    m->myBullets.erase(m->myBullets.begin() + i);
                    vector<Bullet *>(m->myBullets).swap(m->myBullets);
                }
            }
        }

        vector<Tank *> myTanks;
        myTanks.push_back(m->tank);
        for(size_t i = 0; i < m->enemyBullets.size(); i++) {
            if (m->enemyBullets[i] != nullptr) {
                if (m->enemyBullets[i]->isShotMade) {
                    BulletAction ba;
                    ba.shot(*m->enemyBullets[i], myTanks);
                }
                else {
                    delete m->enemyBullets[i];
                    m->enemyBullets[i] = nullptr;
                    m->enemyBullets.erase(m->enemyBullets.begin() + i);
                    vector<Bullet *>(m->enemyBullets).swap(m->enemyBullets);
                }
            }
        }

        if (m->enemyTanks.size() != (size_t)m->countOfEnemyTanks) {
            m->score = m->countOfEnemyTanks - m->enemyTanks.size();
        }

        if (myTanks.empty()) {
            m->stopGame = true;
            m->victory = false;
            return;
        }

        if (m->enemyTanks.empty()) {
            m->stopGame = true;
            m->victory = true;
            return;
        }
        this_thread::sleep_for(chrono::milliseconds(45));

    }

}
