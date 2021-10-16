SELECT
    DISTINCT C1.CART_ID
FROM
    (
        SELECT 
            CART_ID
        FROM
            CART_PRODUCTS
        WHERE
            NAME = 'Yogurt'
    ) AS C1
JOIN
    (
        SELECT 
            CART_ID
        FROM
            CART_PRODUCTS
        WHERE
            NAME = 'Milk'
    ) AS C2
ON
    C1.CART_ID = C2.CART_ID
ORDER BY
    C1.CART_ID;

-- SELECT
--     C1.CART_ID
-- FROM
--     (
--         SELECT 
--             DISTINCT CART_ID, NAME
--         FROM
--             CART_PRODUCTS
--         WHERE
--             NAME IN ('Yogurt','Milk')
--     ) AS C1
-- GROUP BY
--     CART_ID
-- HAVING
--     COUNT(*) > 1