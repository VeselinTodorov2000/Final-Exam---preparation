--  Да се напише заявка, която извежда заглавията и дължините в минути на всички цветни филми
-- без най-дългия цветен и без тези с неизвестна дължина. Ако има няколко филма с максимална дължина,
-- нито един от тях не трябва да бъде изведен.
SELECT m.TITLE, m.LENGTH
FROM MOVIE m
WHERE m.INCOLOR = 'Y' AND m.LENGTH IS NOT NULL AND m.LENGTH < (SELECT MAX(m.LENGTH) FROM MOVIE m WHERE m.INCOLOR='Y');

-- Да се посочи коя от следните заявки извежда имената на тези студиа, които нямат филми или са
-- снимали филми само в една единствена година:
SELECT name
FROM Studio
LEFT JOIN Movie ON name = studioname
GROUP BY name
HAVING COUNT(DISTINCT year) <= 1;
