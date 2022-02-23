#include <iostream>
#include <math.h>
#include <vector>
using std::cout; using std::cin; using std::endl;


class Ship{
	public:
		int mass = 100;
		int id;
		float x; float y;
		int guns_q;
		Ship(int mass, int id, int x, int y, int guns_q, int hp){
                        this->x = x;
                        this->y = y;
                        this->mass = mass;
                        this->id = id;
                        this->guns_q = guns_q;
                        this->hp = hp;
                }
		~Ship(){};
		std::vector<int> speed = {0, 0};
		void hit(int damage){
			this->hp -= damage;
		}
                void Print(){
                        cout << this->mass << " " <<  this->x << " " << this->y << " " << this->id << endl;
                }
		void Check_DeathLine(){
			if(this->x > 10000 || this->x < -10000 || (this->x < 100 && this->x > -100) || (this->y < 100 && this->y > -100) || this->y > 10000 || this->y < -10000){
				cout << "Despawning" << endl;
				exit(0);
			} 
		}
		void move(float movex, float movey){  //Здесь передаваемые переменные будут создаваться двигателями, так что пока считаем их <<заглушкой>>
			int gravx, gravy;
			if(this->x != 0){
				if(this->x > 0)
					gravx = 2 * this->mass;
				else 
					gravx = -2* this->mass;
			}
			else
				gravx = 0;
			if(this->y != 0){
				if(this->y > 0)
					gravy = 2 * this->mass;
				else
					gravy = -2 * this->mass;
			}
			else 
				gravy = 0;
			this->x += movex + this->speed[0] - gravx; 
			this->y += movey + this->speed[1] - gravy; // гравитационный коэффициент допишу уже на этапе создания полного кода
			Check_DeathLine();
			cout << this->x << " " << this->y << endl;
		}
		void die(){
			
		}
		int shoot(){
			int damage = this->guns_q * 3; //коэффициент урона тоже добавлю нормальный позже
			return damage;
		}
	private:
		int hp = 10;

};

int main(){
	Ship s1(100, 1, 9000, -9000, 0, 200);
	s1.Print();
	int i;
	for(int i = 0; i != 100; i++){
	s1.move(0, 0);
	}
	return 0;
}
