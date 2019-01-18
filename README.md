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

# To run the docker container

docker run -it \
-p 3000:3000 -p 3001:3001 -p 3002:3002 -p 80:80 \
-v "/home/data/docker/clamav":/clamav \
kowaraj/test:centos_kj_all_006


# To run a .js file in command line (with node)

// db.js
module.exports.init = function () {
  console.log('hi');
};

// command line
node -e 'require("./db").init()'
