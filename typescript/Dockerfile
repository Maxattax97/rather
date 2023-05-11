FROM node:16 AS builder
WORKDIR /usr/local/src/rather/
COPY ./ ./
RUN npm install && npm run build

FROM node:16-alpine
WORKDIR /usr/local/bin/
COPY --from=builder /usr/local/src/rather/build/rather-bundle.js ./
CMD ["node", "./rather-bundle.js"]
