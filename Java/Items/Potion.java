package Items;
import Characters.*;

public class Potion extends Item {    
//Atributos
	private int restorepts;
	private Characters.Character owner; //Em quem a pocao surte efeito.
//Metodos
	public Potion(String Name, double Price, int Restore){
	super(Name, Price);
	restorepts = Restore;
	}

	public Potion(Potion Source){
	super(Source);
	this.restorepts = Source.getRestorePts();
	}

	public int getRestorePts(){
	return restorepts;
	}

	public int getAttackPts(){
	return 0;
	}

	public int getDefensePts(){
	return restorepts;
	}

	public void setOwner(Characters.Character User){
	owner = User;
	} //Colocar dono so depois da criacao.

	public Characters.Character getOwner(){
	return owner;
	}

	public void use(){
	return;// Potion generica nao tem funcao.
	}
};
