#include <iostream>
#include <chrono>
#include "/home/pi/Code/elma/include/elma.h" // Note installation directory for elma
#include <wiringPi.h>

//! \file

#define	LED	0
using namespace std::chrono;
using namespace elma;

namespace toggle_switch_example {


    //! A process class that sends switch events. See examples/toggle_switch.cc.
    class Trigger : public Process {
        public:

        //! Wrap the base process class
        Trigger() : Process("trigger") {}

        //! Nothing to do for init
        void init() {}

        //! Nothing to do upon starting
        void start() {}

        //! Emit a switch event each time called
        void update() { 
            std::cout << "switch at " << milli_time() << "\n";
            emit(Event("switch"));
        }

        //! Nothing to do to stop
        void stop() {}

    };

    //! A generic state class with nothing more than a name. See examples/toggle_switch.cc.
    class Mode : public State {

        public:
        //! Wrap the base state class
        Mode(std::string name) : State(name) {}

        //! Print something when the state is entered
        void entry(const Event& e) {
            std::cout << "entering " + name() << "\n";
            if(name()=="off")
            {
				digitalWrite (LED, LOW) ;	// Off
			}
			else
			{
				digitalWrite (LED, HIGH) ;	// Off
			}
        }

        //! Do nothing while the state is active
        void during() {std::cout << "checking "<< "\n";}

        //! Do nothing upon exiting the state        
        void exit(const Event&) {}
    };

}

int main() {

    Manager m;
    toggle_switch_example::Trigger trigger;
    toggle_switch_example::Mode off("off"), on("on");
    StateMachine fsm("toggle switch");
    wiringPiSetup () ;
	pinMode (LED, OUTPUT) ;

    fsm.set_initial(on)
       .set_propagate(false)
       .add_transition("switch", off, on)
       .add_transition("switch", on, off);

    m.schedule(trigger, 500_ms)
     .schedule(fsm, 10_ms) // Doesn't matter since mode has empty update()
     .init()
     .run(11000000000_ms);
     
}
