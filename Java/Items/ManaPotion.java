package Items;
import Characters.*;

public class ManaPotion extends Potion {    
//Metodos
	public ManaPotion(String Name, double Price, int Mana){
	super(Name, Price, Mana);
	type = 2; //Indicar que esse item e do tipo Mana Potion
	}

	public void use(){
	//cout << "Mana Potion MP/Restore/Total: " << getOwner().getMP() << " " << getRestorePts() << " "; //Debug Print
	getOwner().addMP(getRestorePts());
	//cout << getOwner().getMP() << endl; //Debug Print
	return;
	}
};
