CREATE TABLE PERSON
(
    PHONE CHAR(12)    NOT NULL PRIMARY KEY,
    NAME  VARCHAR(50) NOT NULL,
    EMAIL VARCHAR(30) NOT NULL
);

CREATE TABLE CLIENT
(
    PHONE CHAR(12) NOT NULL PRIMARY KEY REFERENCES PERSON (PHONE)
);

CREATE TABLE REPAIRMAN
(
    PHONE CHAR(12) NOT NULL PRIMARY KEY REFERENCES PERSON (PHONE)
);

CREATE TABLE SERVICE
(
    REPAIRMAN_PHONE CHAR(12)      NOT NULL PRIMARY KEY REFERENCES REPAIRMAN (PHONE),
    TYPE            VARCHAR(40)   NOT NULL,
    PRICE           DECIMAL(9, 2) NOT NULL
);

CREATE TABLE ORDER
(
    CLIENT_PHONE    CHAR(12)     NOT NULL REFERENCES CLIENT (PHONE),
    ORDER_DATE      DATE         NOT NULL,
    REPAIRMAN_PHONE CHAR(12)     NOT NULL REFERENCES REPAIRMAN (PHONE),
    ADDRESS         VARCHAR(100) NOT NULL,
    DATE_WORKED     DATE         NOT NULL,
    PRIMARY KEY (CLIENT_PHONE, ORDER_DATE)
);