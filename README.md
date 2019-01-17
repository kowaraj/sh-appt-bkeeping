# Based on:

https://blog.pusher.com/reason-react-bucklescript/


# To install:

npm i -g create-react-app

create-react-app reason-bucklescript-todo --scripts-version reason-scripts

npm install neo4j --save

npm start


# To run Neo4j server

docker run \
>     --publish=7474:7474 --publish=7687:7687 \
>     --volume=$HOME/neo4j/data:/data \
>     neo4j
