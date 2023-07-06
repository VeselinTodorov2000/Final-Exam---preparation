CREATE TABLE CLIENTS
(
    PHONE   VARCHAR(12)  NOT NULL PRIMARY KEY,
    NAME    VARCHAR(50)  NOT NULL,
    ADDRESS VARCHAR(150) NOT NULL
);

CREATE TABLE ORDER
(
    ID           CHAR(10)    NOT NULL PRIMARY KEY,
    CLIENT_PHONE VARCHAR(12) NOT NULL REFERENCES CLIENTS (PHONE)
);

CREATE TABLE FOOD
(
    ID            CHAR(5)       NOT NULL PRIMARY KEY,
    PRICE         DECIMAL(9, 2) NOT NULL,
    PIZZANAME     VARCHAR(50),
    WEIGHT        INT CHECK (WEIGHT > 0),
    DRINKNAME     VARCHAR(30),
    DRINKQUANTITY DECIMAL(9, 2) CHECK (DRINKQUANTITY > 0),
    ORDER_ID      CHAR(10)      NOT NULL REFERENCES ORDER (ID)
);

CREATE TABLE PRODUCT
(
    NAME   VARCHAR(30)   NOT NULL PRIMARY KEY,
    PRICE  DECIMAL(9, 2) NOT NULL,
    WEIGHT INT           NOT NULL CHECK (WEIGHT > 0)
);

CREATE TABLE USE
(
    PIZZA_ID     CHAR(5)     NOT NULL REFERENCES FOOD(ID),
    PRODUCT_NAME VARCHAR(30) NOT NULL REFERENCES PRODUCT(NAME),
    PRIMARY KEY (PIZZA_ID, PRODUCT_NAME)
);