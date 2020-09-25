#include "PENDetectorMessenger.hh"

#include "PENDetectorConstruction.hh"
#include "G4UIdirectory.hh"
#include "G4UIcmdWithAString.hh"
#include "G4UIcmdWithADoubleAndUnit.hh"
#include "G4UIcmdWithADouble.hh"
#include "G4UIcmdWithoutParameter.hh"
#include "G4UIcmdWithAnInteger.hh"
#include "G4UIcmdWithABool.hh"

#include "G4RunManager.hh"

class PENDetectorConstruction;
class G4UIdirectory;
class G4UIcmdWithAString;
class G4UIcmdWithADoubleAndUnit;
class G4UIcmdWithADouble;
class G4UIcmdWithoutParameter;
class G4UIcmdWithAnInteger;
class G4UIcmdWithABool;

PENDetectorMessenger::PENDetectorMessenger(PENDetectorConstruction* Det)
	:G4UImessenger(),
	fDetCons(Det),
	fPENDir(0),
	fDetDir(0),
	commandSetWireType(0),
	commandSetConfine(0)
{
	fDetDir = new G4UIdirectory("/PEN/Det/Set");
	fDetDir->SetGuidance("detector construction commands");

	commandSetWireType = new G4UIcmdWithAString("/PEN/Det/Set/WireType", this);
	commandSetWireType->SetGuidance("Select wire type.");
	commandSetWireType->SetParameterName("choice", false);
	commandSetWireType->AvailableForStates(G4State_PreInit, G4State_Idle);
	commandSetWireType->SetToBeBroadcasted(false);

	commandSetConfine = new G4UIcmdWithAString("/PEN/Det/Set/Confine", this);
	commandSetConfine->SetGuidance("Set confine name in file name.");
	commandSetConfine->SetParameterName("choice", false);
	commandSetConfine->AvailableForStates(G4State_PreInit, G4State_Idle);
	commandSetConfine->SetToBeBroadcasted(false);



}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

PENDetectorMessenger::~PENDetectorMessenger()
{
	delete fDetDir;
	delete fPENDir;
	delete commandSetWireType;
	delete commandSetConfine;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void PENDetectorMessenger::SetNewValue(G4UIcommand* command, G4String newValue)
{
	if (command == commandSetWireType) {
		fDetCons->SetWireType(newValue);
	}

	if (command == commandSetConfine) {
		fDetCons->SetConfine(newValue);
	}
}
