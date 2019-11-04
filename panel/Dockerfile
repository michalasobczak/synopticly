FROM ruby:2.5.5

WORKDIR /app

ADD Gemfile /app/Gemfile
ADD Gemfile.lock /app/Gemfile.lock
RUN bundle install --system

ADD . /app
RUN bundle install --system

RUN apt-get update -y && apt-get install nodejs -y

EXPOSE 3000

CMD ["rails", "s", "-b", "0.0.0.0"]
