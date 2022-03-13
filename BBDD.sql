DROP DATABASE IF EXISTS juego;
CREATE DATABASE juego;

USE juego;

CREATE TABLE jugador (
	username VARCHAR(60),
	contraseña VARCHAR(60)
)ENGINE=InnoDB;

CREATE TABLE partida (
	ID_partida VARCHAR(60),
	fecha VARCHAR(11), 
	hora VARCHAR(6), 
	duracion INT,
	ganador VARCHAR(60)
)ENGINE=InnoDB;

INSERT INTO jugador VALUES ('Juan', 'J18');
INSERT INTO jugador VALUES ('Maria', 'M14');
INSERT INTO jugador VALUES ('Luis', 'L23');
INSERT INTO jugador VALUES ('Pedro', 'P11');

INSERT INTO partida VALUES ('1', '13/03/2022', '13:34', 80, 'Juan');
INSERT INTO partida VALUES ('2', '13/03/2022', '14:34', 90, 'Maria');
INSERT INTO partida VALUES ('3', '13/03/2022', '15:34', 100, 'Luis');
INSERT INTO partida VALUES ('4', '13/03/2022', '16:34', 110, 'Pedro');


