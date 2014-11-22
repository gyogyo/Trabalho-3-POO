package Items;

public class Weapon extends Item {    
//Atributos
	protected int attackpts;
	protected double range;

//Metodos
	public Weapon(String Name, double Price, int Attack, double Range){
	super(Name, Price);
	if(Attack > 9) Attack = 9; //Impor limites nos atributos
	else if (Attack < 1) Attack = 1;
	attackpts = Attack;
	range = Range;
	}

	public Weapon(Weapon Source){
	super(Source);
	this.attackpts = Source.attackpts;
	this.range = Source.range;
	}

	public int getAttackPts(){
	return attackpts;
	}

	public int getDefensePts(){
	return 0;
	}

	public double getRange(){
	return range;
	}

	public void use(){}
};
