CREATE TABLE characterStatus(
    stat_id BIGSERIAL UNIQUE NOT NULL PRIMARY KEY,
    user_id BIGSERIAL NOT NULL PRIMARY KEY,
    charcter_id BIGSERIAL NOT NULL,
    current_hp INT NOT NULL,
    current_exp INT NOT NULL
);
