/**
 * SPDX-License-Identifier: GPL-2.0-only
 *
 * This file is part of openstreetmap-cgimap (https://github.com/zerebubuth/openstreetmap-cgimap/).
 *
 * Copyright (C) 2009-2024 by the CGImap developer community.
 * For a full list of authors see the git log.
 */

#ifndef API06_MAP_HANDLER_HPP
#define API06_MAP_HANDLER_HPP

#include "cgimap/bbox.hpp"
#include "cgimap/handler.hpp"
#include "cgimap/osm_current_responder.hpp"
#include "cgimap/request.hpp"
#include "cgimap/request_context.hpp"

#include <string>

namespace api06 {

class map_responder : public osm_current_responder {
public:
  map_responder(mime::type, 
                bbox, 
                data_selection &, 
                const RequestContext& req_ctx);
};

class map_handler : public handler {
public:
  explicit map_handler(request &req);
  std::string log_name() const override;
  responder_ptr_t responder(data_selection &x,
                            const RequestContext& req_ctx) const override;

private:
  bbox bounds;

  static bbox validate_request(const request &req);
};

} // namespace api06

#endif /* API06_MAP_HANDLER_HPP */
