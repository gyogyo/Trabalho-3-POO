package Characters;
public class Knight extends Character {
//Atributos
	protected int power;

//Metodos

	protected int getDefensePoints(){
	int BaseDef = (int) (((constitution*5)+(dexterity*3)+(speed*2))/10);
	int Base = (int) ((BaseDef+getInventory().itemDefPts())*XP)/6;
	int Ret = Base+power;
	return Ret; //Somar power no total de defesa.
	}

	public Knight(String Name, int Power) {
	super(Name);
	power = Power;
	}

	//O gerador de numeros aleatorios dessa funcao ja calcula em porcentagem. (De 0 a 100)
	//A escolha de evitar numeros fracionados foi feita para simplificacao.
	//A chance de ataque critico e 0.02 * (XP/2) = 0.01 * XP = XP%
	//A chance de erro e 0.1/XP = (10/XP)%
	//Essas chances serao ativadas se o RNG gerar um numero porcentual menor que as formulas.

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

	public void addPower(int Amount){
	if((power+Amount)>99) power = 100;
	else power += Amount;
	}
};
