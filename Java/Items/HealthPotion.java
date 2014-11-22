package Items;
import Characters.*;

public class HealthPotion extends Potion {    
//Metodos
	public HealthPotion(String Name, double Price, int Health){
	super(Name, Price, Health);
	type = 1; //Indicar que esse item e do tipo Health Potion
	}

	public void use(){
	// << "Health Potion HP/Restore/Total: " << getOwner().getHP() << " " << getRestorePts() << " "; //Debug Print
	getOwner().addHP(getRestorePts());
	//cout << getOwner().getHP() << endl; //Debug Print
	return;
	}
};
