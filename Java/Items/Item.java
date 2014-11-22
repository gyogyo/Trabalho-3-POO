package Items;

public abstract class Item {
//Atributos
	private String name;
	private double price;

	protected int type; //Tipo do item a ser usado. 1 = HealthPotion, 2 = ManaPotion.
//Metodos
	public Item(String Name, double Price){
	name = Name;
	price = Price;
	type=0;
	}

	public Item(Item Source){
	this.name = Source.name;
	this.price = Source.price;
	}

	public String getName(){
	return name;
	}

	public double getPrice(){
	return price;
	}

	public int getType(){
	return type;
	}

	public abstract void use();
	public abstract int getAttackPts();
	public abstract int getDefensePts();

};
