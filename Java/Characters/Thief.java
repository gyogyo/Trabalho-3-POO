package Characters;
public class Thief extends Character {
//Atributos
	protected int stealth;

//Metodos

	protected int getAttackPoints(){
	int BaseAtk = (int) (((strenght*5)+(dexterity*3)+(speed*2))/10);
	int Base = (int) ((BaseAtk+getInventory().itemAtkPts())*XP)/2;
	int Ret = Base + stealth;
	return Ret; //Somar stealth no ataque. Mas essa soma faria mais sentido se fosse Assassin, não thief. :v
	}

	public Thief(String Name, int Stealth) {
	super(Name);
	stealth = Stealth;
	}

	public void attack(Character Enemy){
	int RanNum = (int) (Math.random()*1000);
	int CritNum = (int) (Math.random()*100);
	int Damage;
	Damage = (int)((getAttackPoints()-Enemy.getDefensePoints()) + (Math.random()*11) - 5);
	if(Damage < 1) {Damage = 1;}
	if(CritNum < (XP)) {Damage *= 2;}
	if(RanNum < (100/XP)) {Damage = 0;}
	//cout << alias << " attacks " << Enemy.getName() << " ! " << Damage << " damage!" << endl; //Debug Print
	Enemy.addHP(-Damage); //Tirar o dano da vida do oponente.
	}

	public void addStealth(int Amount){
	if((stealth+Amount)>99) stealth = 100;
	else stealth += Amount;
	}

};
