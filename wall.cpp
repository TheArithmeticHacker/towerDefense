#include "wall.h"

Wall::Wall() {
    health = 10;
    setPixmap(QPixmap(":/img/Images/wall.jpg").scaled(100, 100));
}

void Wall::increase(){if(health < 10) health++;}
void Wall::decrease(int dmg){health-=dmg;}
bool Wall::isDestroyed(){return health <= 0;}
