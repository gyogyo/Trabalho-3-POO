package Characters;
public class Wizard extends Character {
//Atributos
	protected int wisdom;

//Metodos

	protected int getDefensePoints(){
	int BaseDef = (int) (((constitution*5)+(dexterity*3)+(speed*2))/10);
	int Base = (int) ((BaseDef+getInventory().itemDefPts())*XP)/6;
	int Ret = Base+(wisdom/2);
	return Ret; //Somar metade de wisdom na defesa.
	}

	public Wizard(String Name, int Wisdom) {
	super(Name);
	wisdom = Wisdom;
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

	public void addWisdom(int Amount){
	if((wisdom+Amount)>99) wisdom = 100;
	else wisdom += Amount;
	}
};
