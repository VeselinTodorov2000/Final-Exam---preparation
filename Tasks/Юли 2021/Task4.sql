SELECT code, price FROM Laptop
WHERE screen BETWEEN 13 AND 15
AND ram IN (SELECT ram
FROM PC);

SELECT maker, COUNT(code) FROM Laptop
RIGHT JOIN Product
ON Laptop.model = Product.model
AND screen = 15
GROUP BY maker