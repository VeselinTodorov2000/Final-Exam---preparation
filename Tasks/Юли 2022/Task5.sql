SELECT s.name, m.title
FROM movie m JOIN studio s ON m.studioname = s.name
WHERE s.name IN (SELECT n.studioname
FROM Movie n
WHERE title = 'The Usual Suspects' AND year = 1995);

SELECT ms.name, si.movietitle
FROM moviestar ms
LEFT JOIN starsin si
ON ms.name=si.starname
WHERE si.movietitle IS NULL;