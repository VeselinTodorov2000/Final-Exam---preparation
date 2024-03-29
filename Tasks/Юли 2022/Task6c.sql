CREATE TABLE CLIENTS
(
    EMAIL VARCHAR(30) NOT NULL PRIMARY KEY,
    NAME  VARCHAR(50) NOT NULL
);

CREATE TABLE HOTELS
(
    NAME    VARCHAR(30) NOT NULL PRIMARY KEY,
    ADDRESS VARCHAR(50) NOT NULL,
    STARS   INT         NOT NULL CHECK (STARS >= 0 AND STARS <= 7)
);

CREATE TABLE ROOMS
(
    NUMBER INT           NOT NULL CHECK (NUMBER > 0),
    NAME   VARCHAR(30)   NOT NULL REFERENCES HOTELS (NAME),
    TYPE   VARCHAR(10)   NOT NULL,
    PRICE  DECIMAL(9, 2) NOT NULL CHECK ( PRICE >= 0),
    PRIMARY KEY (NAME, NUMBER)
);

CREATE TABLE BOOKINGS
(
    NUMBER CHAR(8) NOT NULL PRIMARY KEY,
    BOOKING_DATE DATE NOT NULL,
    START_DATE DATE NOT NULL,
    END_DATE DATE NOT NULL,
    STATUS CHAR(5) NOT NULL,
    PRICE DECIMAL(9,2) NOT NULL CHECK (PRICE > 0),
    HOTEL_NAME VARCHAR(30) NOT NULL,
    ROOM_NUMBER INT NOT NULL,
    EMAIL VARCHAR(30) NOT NULL REFERENCES CLIENTS(EMAIL),
    FOREIGN KEY (HOTEL_NAME, ROOM_NUMBER) REFERENCES ROOMS(NAME, NUMBER)
);
