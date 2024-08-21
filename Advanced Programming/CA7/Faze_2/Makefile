all: futballFantasy.out

futballFantasy.out: indep_functions.o Player.o Goalkeeper.o Defender.o Midifielder.o Forward.o Team.o User.o Futball.o dependent_funcs.o Run.o futballFantasy.o
	g++ --std=c++11 indep_functions.o Player.o Goalkeeper.o Defender.o Midifielder.o Forward.o Team.o User.o Futball.o dependent_funcs.o Run.o futballFantasy.o -o futballFantasy.out

futballFantasy.o: futballFantasy.cpp Run.hpp
	g++ --std=c++11 -c futballFantasy.cpp

indep_functions.o: indep_functions.cpp Constants.hpp indep_functions.hpp
	g++ --std=c++11 -c indep_functions.cpp

Player.o: Player.cpp Match.hpp Player.hpp
	g++ --std=c++11 -c Player.cpp

Goalkeeper.o: Goalkeeper.cpp Player.hpp Goalkeeper.hpp
	g++ --std=c++11 -c Goalkeeper.cpp

Defender.o: Defender.cpp Player.hpp Defender.hpp
	g++ --std=c++11 -c Defender.cpp

Midifielder.o: Midifielder.cpp Player.hpp Midifielder.hpp
	g++ --std=c++11 -c Midifielder.cpp

Forward.o: Forward.cpp Player.hpp Forward.hpp
	g++ --std=c++11 -c Forward.cpp

Team.o: Team.cpp Player.hpp Team.hpp
	g++ --std=c++11 -c Team.cpp

User.o: User.cpp Team.hpp User.hpp
	g++ --std=c++11 -c User.cpp

Futball.o: Futball.cpp Week.hpp Futball.hpp
	g++ --std=c++11 -c Futball.cpp

dependent_funcs.o: dependent_funcs.cpp Futball.hpp dependent_funcs.hpp
	g++ --std=c++11 -c dependent_funcs.cpp

Run.o: Run.cpp dependent_funcs.hpp Run.hpp
	g++ --std=c++11 -c Run.cpp

clean:
	rm *.o futballFantasy.out