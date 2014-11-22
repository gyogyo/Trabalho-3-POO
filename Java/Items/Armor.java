package Items;

public class Armor extends Item {    
//Atributos
	protected int defensepts;
	protected double weight;

//Metodos
	public Armor(String Name, double Price, int Defense, double Weight){
	super(Name, Price);
	if(Defense > 20) Defense = 20; //Impor limites.
	else if (Defense < 1) Defense = 1;
	defensepts = Defense;
	weight = Weight;
	}

	public Armor(Armor Source){
	super(Source);
	this.defensepts = Source.defensepts;
	this.weight = Source.weight;
	}

	public int getAttackPts(){
	return 0;
	}

	public int getDefensePts(){
	return defensepts;
	}

	public double getWeight(){
	return weight;
	}

	public void use(){return;}
};
